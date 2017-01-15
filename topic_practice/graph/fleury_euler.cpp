#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_);
	void add_edge(int x, int y);
	int dfscount(int s, int *visited);
	void print_fleury();
	int is_eulerian();
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y) {
	adj[x].push_back(y);
	adj[y].push_back(x);
}
int graph::dfscount(int s, int *visited){
	int cnt = 0;
	visited[s] = 1;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(*it != -1 and visited[*it] == 0){
			cnt += dfscount(*it, visited);
		}
	}
	visited[s] = 2;
	return cnt;
}
int graph::is_eulerian() {
	int i, cnt;
	int *visited = new int[v];
	for(i = 0 ; i < v ; i++){
		if(adj[i].size() > 0)
			break;
	}
	if(i == v)
		return 2;
	cnt = dfscount(i, visited);
	for(i = 0 ; i < v ; i++){
		if(visited[i] == 0)
			return 0;
	}
	cnt = 0;
	for(i = 0 ; i < v ; i++){
		if(adj[i].size() % 2 != 0)
			cnt++;
		if(cnt > 2)
			return 0;
	}
	if(cnt == 0)
		return 2;
	if(cnt == 2)
		return 1;
}
void graph::print_fleury(){
	int k, i, cnt, *visited, j, pos, cnt_new, temp, h;
	visited = new int[v];
	k = is_eulerian();
	if(k == 0)
		return;
	i = 0;
	if(k == 1){
		for(j = 0 ; j < v ; j++){
			if(adj[j].size() % 2 != 0)
				break;
		}
		i = j;
	}
	printf("Fleury Euler path :\n");
	while(true) {
		printf("%d ", i);
		cnt = 0;
		pos = -1;
		typeof(adj[i].begin()) it, it1;
		h = 0;
		for(it = adj[i].begin() ; it != adj[i].end() ; it++) {
			if(*it != -1){
				cnt++;
				pos = *it;
				h = distance(adj[i].begin(), it);
			}
		}
		if(cnt == 1){
			it = adj[i].begin();
			advance(it, h);
			it1 = find(adj[*it].begin(),adj[*it].end(),i);
			if(it1 != adj[*it].end())
				*it1 = -1;
			*it = -1;
			i = pos;
		}
		else if(cnt == 0){
			break;
		}
		else{
			for(it = adj[i].begin() ; it != adj[i].end() ; it++) {
				if(*it != -1){
					for(j = 0 ; j < v ; j++)
						visited[j] = 0;
					cnt = dfscount(i, visited);
					for(j = 0 ; j < v ; j++)
						visited[j] = 0;
					temp = *it;
					it1 = find(adj[*it].begin(),adj[*it].end(),i);
					if(it1 != adj[*it].end())
						*it1 = -1;
					*it = -1;
					cnt_new = dfscount(i, visited);
					if(cnt > cnt_new){
						*it = temp;
						*it1 = i;
					}
					else{
						i = temp;
						break;
					}
				}
			}
		}
	}
}
int main() {
	int v, e, x, y;
	printf("Enter the no. of vertices and edges in the grpah (v e) : ");
	scanf("%d%d", &v, &e);
	graph g(v);
	printf("Enter the graph edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	g.print_fleury();
	printf("\n");
	return 0;
}