#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, f;
	list < int > *adj;
public:
	graph(int v_, int f_);
	void add_edge(int x, int y);
	void check_tree();
	int dfs_visit(int s, int *visited);
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y){
	adj[x].push_back(y);
}
int graph::dfs_visit(int s, int *visited) {
	int k;
	visited[s] = 1;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[*it] == 0){
			k = dfs_visit(*it, visited);
			if(k == 1)
				return 1;
		}
		else
			return 1;
	}
	return 0;
}
void graph::check_tree() {
	if(f == 0){
		printf("The graph is directed. Only an undirected graph can be a tree\n");
		return;
	}
	int *visited = new int[v];
	int k = dfs_visit(0,visited);
	if(k == 1){
		printf("The graph has a cycle. So cannot be a tree\n");
		return;
	}
	k = 0;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			k == 1;
			break;
		}
	}
	if(k == 1){
		printf("The graph is no connected. Hence cannot be a tree\n");
		return;
	}
	else{
		printf("The graph is a tree\n");
	}
}
int main(){
	int n, e, f, x, y;
	printf("Enter the no. of vertices and edges in the graph (v e) :\n");
	scanf("%d%d", &n, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(n,f);
	printf("Enter the graph edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	g.check_tree();
	return 0;
}
