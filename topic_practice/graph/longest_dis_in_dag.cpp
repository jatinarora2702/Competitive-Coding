#include <iostream>
#include <stdio.h>
#include <list>
#define INF 1000000007
using namespace std;
class graph{
	int v;
	list < pair < int, int > > *adj;
	void topo_visit(int s, int *visited, list < int >& stk);
public:
	graph(int v_);
	void add_edge(int x, int y, int w);
	void get_longest_dis(int s);
	int* topo_sort();
};
graph::graph(int v_) : v(v_) {
	adj = new list < pair < int, int > > [v];
}
void graph::add_edge(int x, int y, int w) {
	adj[x].push_back(make_pair(y,w));
}
void graph::topo_visit(int s, int *visited, list < int >& stk) {
	visited[s] = 1;
	list < pair < int, int > > :: iterator it;
	for(it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[(*it).first] == 0)
			topo_visit((*it).first, visited, stk);
	}
	stk.push_back(s);
	visited[s] = 2;
}
int* graph::topo_sort() {
	int *p = new int[v];
	int *visited = new int[v];
	list < int > stk;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0)
			topo_visit(i, visited, stk);
	}
	list < int > :: reverse_iterator it;
	int k = 0;
	for(it = stk.rbegin() ; it != stk.rend() ; it++)
		p[k++] = *it;
	return p;
}
void graph::get_longest_dis(int s) {
	int *p = topo_sort();
	int *d = new int[v];
	for(int i = 0 ; i < v ; i++)
		d[i] = -INF;
	d[s] = 0;
	for(int i = 0 ; i < v ; i++){
		if(d[i] == -INF)
			continue;
		for(typeof(adj[i].begin()) it = adj[i].begin() ; it != adj[i].end() ; it++) {
			if(d[(*it).first] < d[i] + (*it).second)
				d[(*it).first] = d[i] + (*it).second;
		}
	}
	printf("Longest distances are :\n");
	for(int i = 0 ; i < v ; i++){
		printf("dist[%d] = %d\n", i, d[i]);
	}
	printf("\n");
}
int main() {
	int n, e, x, y, w;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	printf("Enter the graph edges in format (u v w) :\n");
	graph g(n);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g.add_edge(x, y, w);
	}
	printf("Enter the vertex from which the longest distance is to be measured : ");
	scanf("%d", &x);
	printf("The distances are :\n");
	g.get_longest_dis(x);
	return 0;
}