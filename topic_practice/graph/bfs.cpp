#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, f;
	list < int > *adj;
public:
	graph(int v_, int f_);
	void add_edge(int u, int v);
	void bfs(int s);
};
graph::graph(int v_, int f_){
	v = v_;
	f = f_;
	adj = new list < int >[v];
}
void graph::add_edge(int u, int v){
	adj[u].push_back(v);
	if(f == 1)
		adj[v].push_back(u);
}
void graph::bfs(int s){
	bool *visited;
	list < int > q;
	int u;
	list<int>::iterator it;
	visited = new bool[v];
	for(int i = 0 ; i < v ; i++)
		visited[i] = false;
	q.push_back(s);
	visited[s] = true;
	while(!q.empty()){
		u = q.front();
		printf("%d ", u);
		q.pop_front();
		for(it = adj[u].begin() ; it != adj[u].end() ; it++){
			if(visited[*it] == false){
				q.push_back(*it);
				visited[*it] = true;
			}
		}
	}
	printf("\n");
}
int main(){
	int n, e, f, u, v;
	printf("Enter the no. of nodes and edges of the graph (v e) : ");
	scanf("%d%d", &n, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(n, f);
	printf("Enter the edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &u, &v);
		g.add_edge(u, v);
	}
	printf("Enter the source vertex for BFS : ");
	scanf("%d", &v);
	g.bfs(v);
	return 0;
}