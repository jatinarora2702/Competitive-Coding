#include <iostream>
#include <list>
#include <stdio.h>
#include <iterator>
using namespace std;
class graph{
	int v;
public:
	list < int > *adj;
	list < pair < int, int> > q;
	graph(int v_);
	void add_edge(int x, int y);
	void bfs_make(int s, int *init, int *g, int *key);
	void bfs(int s, int *key);
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void graph::bfs_make(int s, int *init, int *g, int *key){
	int *visited = new int[v];
	int val;
	int i;
	q.clear();
	for(int i = 0 ; i < v ; i++)
		visited[i] = 0;
	visited[s] = 1;
	q.push_back(make_pair(init[s],g[s]));
	key[0] = s;
	list < int > tempq;
	tempq.push_back(s);
	list < int > :: iterator it;
	i = 1;
	while(tempq.size() != 0){
		val = tempq.front();
		//cout << "val=" << val << endl;
		tempq.pop_front();
		for(it = adj[val].begin() ; it != adj[val].end() ; it++){
			if(*it > val and visited[*it] == 0){
				visited[*it] = 1;
				q.push_back(make_pair(init[*it], g[*it]));
				key[i] = *it;
				i++;
				tempq.push_back(*it);
			}
		}
		visited[val] = 2;
	}
}
void graph::bfs(int s, int *key){
	pair < int, int > p1;
	list < pair < int,int > > :: iterator it = q.begin();
	advance(it,s);
	cout << "s=" << key[s]+1 << endl;
	int *visited = new int[v];
	int val;
	int f = 1;
	list < pair < int, int > > tempq;
	for(int i = 0 ; i < v ; i++)
		visited[i] = 0;
	(*it).first = (*it).second;
	it++;
	visited[s] = 1;
	tempq.push_back(make_pair(key[s],0));
	list < int > :: iterator itq;
	while(tempq.size() != 0){
		p1 = tempq.front();
		val = p1.first;
		f = p1.second;
		cout << val+1 << "qpqpq\n";
		tempq.pop_front();
		for(itq = adj[val].begin() ; itq != adj[val].end() ; itq++){
			if(*itq > val and visited[*itq] == 0){
				visited[*itq] = 1;
				tempq.push_back(make_pair(*itq,!f));
				cout << *itq+1 << "before:" << (*it).first << endl;
				(*it).first ^= f;
				cout << *itq+1 << "after:" << (*it).first << endl;
				it++;
			}
			else //if(*itq > val and visited[*itq] == 1)
				it++;
			int j = 0;
			for(typeof(q.begin()) it1 = q.begin() ; it1 != q.end() ; it1++){
				printf("%d[%d %d]\n", key[j]+1, (*it1).first, (*it1).second);
				j++;
			}
			printf("done %d\n", s);
		}
	}
	int j = 0;
	for(typeof(q.begin()) it1 = q.begin() ; it1 != q.end() ; it1++){
		printf("%d[%d %d]\n", key[j]+1, (*it1).first, (*it1).second);
		j++;
	}
	printf("done %d\n", s);
}
int main(){
	int n, x, y, *init, *g, j, cnt, *pos, *key;
	scanf("%d", &n);
	graph gr(n);
	init = new int[n];
	g = new int[n];
	pos = new int[n];
	key = new int[n];
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		gr.add_edge(x,y);
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &init[i]);
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &g[i]);
	}
	for(int i = 0 ; i < n ; i++){
		printf("%d : ", i+1);
		for(typeof(gr.adj[i].begin()) it1 = gr.adj[i].begin() ; it1 != gr.adj[i].end() ; it1++){
			printf("%d ", *it1+1);
		}
		printf("\n");	
	}
	gr.bfs_make(0,init,g, key);
	list < pair < int, int > > :: iterator it;
	j = 0;
	for(it = gr.q.begin() ; it != gr.q.end() ; it++){
		printf("%d[%d %d]\n", key[j]+1, (*it).first, (*it).second);
		j++;
	}
	j = 0;
	cnt = 0;
	for(it = gr.q.begin() ; it != gr.q.end() ; it++){
		//cout << "i\n";
		if((*it).first != (*it).second){
			gr.bfs(j,key);
			pos[cnt] = j;
			cnt++;
		}
		j++;
	}
	printf("%d\n", cnt);
	for(int i = 0 ; i < cnt ; i++){
		printf("%d\n", key[pos[i]]+1);
	}
	return 0;
}