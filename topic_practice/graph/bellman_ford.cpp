#include <iostream>
#include <stdio.h>
#include <list>
#define INF 1000000007
using namespace std;
class graph{
	int v, f;
	list < pair < int, int > > *adj;
public:
	graph(int v_, int f_);
	void add_edge(int x, int y, int w);
	void bellman_ford(int s);
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new list < pair < int, int > > [v];
}
void graph::add_edge(int x, int y, int w) {
	adj[x].push_back(make_pair(y,w));
	if(f)
		adj[y].push_back(make_pair(x,w));
}
void graph::bellman_ford(int s){
	int *d = new int[v];
	for(int i = 0 ; i < v ; i++){
		d[i] = INF;
	}
	d[s] = 0;
	for(int i = 0 ; i < v-1 ; i++){
		for(int j = 0 ; j < v ; j++){
			for(typeof(adj[j].begin()) it = adj[j].begin() ; it != adj[j].end() ; it++) {
				if(d[(*it).first] > d[j] + (*it).second){
					d[(*it).first] = d[j] + (*it).second;
				}
			}	
		}
	}
	int f = 0;
	for(int j = 0 ; j < v ; j++){
		for(typeof(adj[j].begin()) it = adj[j].begin() ; it != adj[j].end() ; it++) {
			if(d[(*it).first] > d[j] + (*it).second){
				f = 1;
				break;
			}
		}	
	}
	if(f == 1){
		printf("The graph has a negative wt. cycle\n");
	}
	else{
		printf("min_dist : ");
		for(int i = 0 ; i < v ; i++){
			printf("%d ", d[i]);
		}
		printf("\n");
	}
}
int main(){
	int v, e, x, y, w, f, s;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &v, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(v,f);
	printf("Enter the edges (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g.add_edge(x, y, w);
	}
	printf("Enter the source vertex for shortest distances : ");
	scanf("%d", &s);
	g.bellman_ford(s);
	return 0;
}