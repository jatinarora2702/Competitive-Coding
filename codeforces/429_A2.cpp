#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v;
	list < int > *adj;
	int *visited;
public:
	int *g, *init;
	list < int > vt;
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		g = new int[v];
		init = new int[v];
		visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs(int s, int f, int p){
		visited[s] = 1;
		if(g[s] != init[s] ^ f){
			f = f ^ 1;
			vt.push_back(s);
		}
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0)
				dfs(*it, p, f);
		}
	}
};
int main(){
	int n, x, y, *arr, cnt;
	scanf("%d", &n);
	graph gr(n);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		gr.add_edge(x, y);
	}
	arr = new int[n];
	for(int i = 0 ; i < n ; i++)
		arr[i] = 0;
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &gr.init[i]);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &gr.g[i]);
	cnt = 0;
	gr.dfs(0, 0, 0);
	cout << gr.vt.size() << endl;
	list < int > :: iterator it;
	for(it = gr.vt.begin() ; it != gr.vt.end() ; it++)
		printf("%d\n", (*it)+1);
	return 0;
}