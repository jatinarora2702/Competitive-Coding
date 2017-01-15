#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
public:
	int v;
	list < int > *adj;
	graph(int v_);
	void add_edge(int x, int y);
	void get_stack(list < int > &stk);
	void get_scc(list < int > &stk);
	void dfs_visit_rev(int *visited, int s);
	void dfs_visit(int *visited, list < int > &stk, int s);
	static graph revgraph(graph g);
	void print();
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y) {
	adj[x].push_back(y);
}
graph graph::revgraph(graph g){
	graph rg(g.v);
	
	printf("printing graph :\n");
	for(int i = 0 ; i < g.v ; i++){
		printf("%d : ", i);
		for(typeof(g.adj[i].begin()) it = g.adj[i].begin() ; it != g.adj[i].end() ; it++){
			printf("%d ", *it);
		}
		printf("\n");
	}
	for(int i = 0 ; i < g.v ; i++){
		for(typeof(g.adj[i].begin()) it = g.adj[i].begin() ; it != g.adj[i].end() ; it++){
			rg.add_edge(*it,i);
		}
	}
	return rg;
}
void graph::dfs_visit(int *visited, list < int > &stk, int s) {
	visited[s] = 1;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[*it] == 0)
			dfs_visit(visited, stk, *it);
	}
	visited[s] = 2;
	stk.push_back(s);
}
void graph::dfs_visit_rev(int *visited, int s) {
	visited[s] = 1;
	printf("%d ", s);
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[*it] == 0)
			dfs_visit_rev(visited, *it);
	}
	visited[s] = 2;
}
void graph::get_stack(list < int > &stk){
	int *visited;
	visited = new int[v];
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			dfs_visit(visited,stk,i);
		}
	}
}
void graph::get_scc(list < int > &stk){
	int *visited = new int[v];
	while(stk.size() > 0){
		printf("Component : ");
		dfs_visit_rev(visited, stk.back());
		printf("\n");
		while(stk.size() > 0 and visited[stk.back()] != 0){
			stk.pop_back();
		}
	}
}
void graph::print(){
	printf("printing graph :\n");
	for(int i = 0 ; i < v ; i++){
		printf("%d : ", i);
		for(typeof(adj[i].begin()) it = adj[i].begin() ; it != adj[i].end() ; it++){
			printf("%d ", *it);
		}
		printf("\n");
	}
}
int main() {
	int v, e, x, y;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &v, &e);
	graph g(v);
	printf("Enter the graph edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	graph rg = g.revgraph(g);
	rg.print();
	list < int > stk;
	g.get_stack(stk);
	rg.get_scc(stk);
	return 0;
}