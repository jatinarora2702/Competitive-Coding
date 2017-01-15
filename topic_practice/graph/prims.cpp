#include <iostream>
#include <stdio.h>
#include <list>
#define INF 1000000007
using namespace std;
class graph{
	int v;
	list < pair < int,int > > *adj;
public:
	graph(int v_);
	void add_edge(int x, int y, int w);
	void mst_prims();
};
graph::graph(int v_) : v(v_) {
	adj = new list < pair < int,int > > [v];
}
void graph::add_edge(int x, int y, int w){
	adj[x].push_back(make_pair(y,w));
	adj[y].push_back(make_pair(x,w));
}
void graph::mst_prims() {
	int min;
	int *p = new int[v];
	int *key = new int[v];
	int *ins = new int[v];
	list < pair < int,int > > :: iterator it;
	for(int i = 0 ; i < v ; i++)
		p[i] = -1;
	for(int i = 1 ; i < v ; i++)
		key[i] = INF;
	for(int i = 0 ; i < v ; i++){
		min = -1;
		for(int j = 0 ; j < v ; j++) {
			if(ins[j] == 0){
				if(min == -1)
					min = j;	
				else if(key[j] < key[min])
					min = j;
			}
		}
		ins[min] = 1;
		for(it = adj[min].begin() ; it != adj[min].end() ; it++){
			if(key[(*it).first] > key[min] + (*it).second){
				key[(*it).first] = key[min] + (*it).second;
				p[(*it).first] = min;
			}
		}
	}
	printf("pts : ");
	for(int i = 0 ; i < v ; i++){
		printf("%2d ", i);
	}
	printf("\nkey : ");
	for(int i = 0 ; i < v ; i++){
		printf("%2d ", key[i]-key[p[i]]);
	}
	printf("\nprt : ");
	for(int i = 0 ; i < v ; i++){
		printf("%2d ", p[i]);
	}
	printf("\n");
}
int main(){
	int n, e, x, y, w;
	printf("Enter the no. of vertices and edges (v e) : ");
	scanf("%d%d", &n, &e);
	graph g(n);
	printf("Enter the edges (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g.add_edge(x, y, w);
	}
	g.mst_prims();
	return 0;
}