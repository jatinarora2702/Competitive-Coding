#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, f;
	list < pair <int,int> > *adj;
	int dfs_visit(int s, int *visited);	
public:
	graph(int v_, int f_);
	void add_edge(int x, int y, int w);
	void detect_cycle();
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new list < pair <int,int> > [v];
}
void graph::add_edge(int x, int y, int w) {
	adj[x].push_back(make_pair(y,w));
	if(f == 1)
		adj[y].push_back(make_pair(x,w));
}
void graph::detect_cycle(){
	int *visited, v, n1;
	visited = new int[v];
	for(int i = 0 ; i < v ; i++)
		visited[i] = 0;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0)
			n1 = dfs_visit(i,visited);
		if(n1 == 1)
			break;
	}
	if(n1 == 1)
		printf("cycle detected\n");
	else
		printf("no cycle detected\n");
}
int graph::dfs_visit(int s, int *visited){
	int v;
	visited[s] = 1;
	list < pair < int , int > > :: iterator it;
	for(it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[(*it).first] == 1){
			return 1;
		}
		else if(visited[(*it).first] == 0){
			v = dfs_visit((*it).first, visited);
			if(v == 1)
				return 1;
		}
	}
	visited[s] = 2;
	return 0;
}int main() {
	int n, e, f, u, v, w;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(n, f);
	printf("Enter the edges of the graph (u v w) :\n");
	for(int i = 0 ; i < e ; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g.add_edge(u, v, w);
	} 
	g.detect_cycle();
	return 0;
}