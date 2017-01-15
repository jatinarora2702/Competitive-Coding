#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class undir_graph{
	int v;
	list < int > *adj;
public:
	undir_graph(int v_);
	void add_edge(int x, int y);
	int detect_cycle();
};
undir_graph::undir_graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void undir_graph::add_edge(int x, int y) {
	adj[x].push_back(y);
	//adj[y].push_back(x);
}
int find(int p[], int i){
	while(p[i] != -1)
		i = p[i];
	return i;
}
void unions(int p[], int i, int j) {
	p[i] = j;
}
int undir_graph::detect_cycle() {
	int *p;
	p = new int[v];
	for(int i = 0 ; i < v ; i++)
		p[i] = -1;
	list < int > :: iterator it;
	for(int i = 0 ; i < v ; i++){
		for(it = adj[i].begin() ; it != adj[i].end() ; it++){
			int x1 = find(p, *it);
			int x2 = find(p,i);
			if(x1 == x2 and x1 != -1)
				return 1;
			else
				unions(p,*it,i);
		}
	}
	return 0;
}
int main() {
	int n, e, u, v;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	undir_graph g(n);
	printf("Enter the edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &u, &v);
		g.add_edge(u,v);
	}
	if(g.detect_cycle())
		printf("cycle detected\n");
	else
		printf("no cycle detected\n");
	return 0;
}