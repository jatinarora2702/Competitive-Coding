#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, f;
	list < pair < int , int > > *adj;
	void dfs_visit(int s, int *visited);
public:
	graph(int v_, int f_);
	void add_edge(int x, int y, int w);
	void dfs(int s);
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new list < pair < int, int > >[v];
}
void graph::add_edge(int x, int y, int w) {
	adj[x].push_back(make_pair(y,w));
	if(f == 1)
		adj[y].push_back(make_pair(x,w));
}
void graph::dfs(int s){
	int *visited;
	visited = new int[v];
	for(int i = 0 ; i < v ; i++)
		visited[i] = 0;
	dfs_visit(s,visited);
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0)
			dfs_visit(i, visited);
	}
	printf("\n");
}
void graph::dfs_visit(int s, int *visited){
	visited[s] = 1;
	printf("%d ", s);
	list < pair < int, int> >::iterator it;
	for(it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[(*it).first] == 0){
			dfs_visit((*it).first, visited);
		}
	}
	visited[s] = 2;
}
int main(){
	int n, e, f, u, v, w;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &v, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(v,f);
	printf("Enter the edges of the graph (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &u, &v, &w);
		g.add_edge(u,v,w);
	}
	printf("Enter the source vertex to start dfs : ");
	scanf("%d", &v);
	g.dfs(v);
	return 0;
}