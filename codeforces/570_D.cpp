#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
#include <utility>
#define ff first
#define ss second
using namespace std;
typedef struct{
	int v;
	list < int > *adj;
	list < char > *ht_str;
public:
	graph(int v_) : v(v_){
		adj = new list < int > [v];
		ht_str = new list < char > [v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
	}
	void bfs(int *a, int s){
		int *visited = new int[v];
		stack < pair < int, pair < int, int > > > stk;
		list < int > :: iterator it;
		pair < int, pair < int, int > > p;
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		visited[s] = 1;
		stk.push(make_pair(a[s], make_pair(s, 0)));
		while(!stk.empty()){
			p = stk.top();
			stk.pop();
			ht_str[p.ss.ss].push_back(p.ff);
			s = p.ss.ff;
			for(it = adj[s].begin() ; it != adj[s].end() ; it++){
				if(visited[*it] == 0){
					visited[*it] = 1;
					stk.push(*it);
				}
			}
			visited[s] = 2;
		}
	}
	
}
int main(){
	int n, *a, m, x, y;
	scanf("%d%d", &n, &m);
	a = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);

}