#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, f;
	list < int > *adj;
public:
	graph(int v_, int f_);
	void add_egde(int x, int y);
	void is_bipartite();
	int dfs_visit(int s, int *visited, int *p, int c);
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new list < int > [v];
}
void graph::add_egde(int x, int y){
	adj[x].push_back(y);
	if(f)
		adj[y].push_back(x);
}
int graph::dfs_visit(int s, int *visited, int *p, int c){
	visited[s] = 1;
	p[s] = c;
	int k;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[*it] == 0){
			k = dfs_visit(*it,visited,p,c+1);
			if(k == 1)
				return 1;
		}
		else if(p[*it]-p[s] % 2 == 0)
			return 1;
	}
	return 0;
}
void graph::is_bipartite(){
	int *visited = new int[v];
	int *p = new int[v];
	int k;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			k = dfs_visit(i,visited,p,0);
			if(k == 1){
				printf("graph is not bipartite\n");
				break;
			}
		}
	}
	if(k == 0)
		printf("graph is bipartite\n");
}
int main(){
	int n, e, f, x, y;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	printf("Enter the graph edges (u v):\n");
	graph g(n,f);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_egde(x,y);
	}
	g.is_bipartite();
	return 0;
}