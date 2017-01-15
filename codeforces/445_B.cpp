#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
typedef unsigned long long int ulli;
class graph{
	int v;
	ulli cost;
	list < int > *adj;
public:
	graph(int v_);
	void add_edge(int u, int v);
	void dfs();
	void dfs_visit(int s, int *visited);
};
graph::graph(int v_) : v(v_){
	adj = new list < int > [v];
	cost = 1;
}
void graph::add_edge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void graph::dfs_visit(int s, int *visited) {
	//cout << "s=" << s << " cost=" << cost << endl;
	visited[s] = 1;
	list < int > :: iterator it;
	for(it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[*it] == 0){
			cost *= (ulli)2;
			dfs_visit(*it, visited);
		}
	}
}
void graph::dfs(){
	int *visited;
	visited = new int[v];
	for(int i = 0 ; i < v ; i++)
		visited[i] = 0;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0)
			dfs_visit(i,visited);
	}
	cout << cost;
}
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	graph g(n);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x,y);
	}
	g.dfs();
	return 0;
}