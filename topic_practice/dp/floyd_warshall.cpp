#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef struct NODE{
	int v,w;
	struct NODE* next;
}node;
typedef struct {
	int v,e;
	node *adjlist;
}graph;
int main() {
	graph g;
	int x, y, z, f, **dp, v;
	printf("Enter the no. of vertices in the graph : ");
	scanf("%d", &g.v);
	printf("Enter the no. of edges in the graph : ");
	scanf("%d", &g.e);
	printf("Is the graph directed(0) or undirected(1) ? : ");
	scanf("%d", &f);
	g.adjlist = new node[g.v];
	for(int i = 0 ; i < g.v ; i++ ) {
		g.adjlist[i].v = g.adjlist[i].w = 0;
		g.adjlist[i].next = NULL;
	}
	printf("Enter the edge info. in the form (u v w) :\n");
	for(int i = 0 ; i < g.e ; i++ ) {
		scanf("%d%d%d", &x, &y, &z);
		node *n = new node;
		n -> v = y;
		n -> w = z;
		n -> next = g.adjlist[x].next;
		g.adjlist[x].next = n;
		if(f == 1){
			n = new node;
			n -> v = x;
			n -> w = z;
			n -> next = g.adjlist[y].next;
			g.adjlist[y].next = n;
		}
	}
	dp = new int*[g.v];
	for(int i = 0 ; i < g.v ; i++ ) {
		dp[i] = new int[g.v];
	}
	for(int i = 0 ; i < g.v ; i++ ) {
		for(int j = 0 ; j < g.v ; j++ ) {
			if(i == j)
				dp[i][j] = 0;
			else{
				dp[i][j] = INF;
				node *n = g.adjlist[i].next;
				while(n != NULL){
					if(n -> v == j){
						dp[i][j] = n -> w;
						break;
					}
					n = n -> next;
				}
			}
		}
	}
	for(int k = 0 ; k < g.v ; k++ ) {
		for(int i = 0 ; i < g.v ; i++ ) {
			for(int j = 0 ; j < g.v ; j++ ) {
				if(i == k or j == k)
					continue;
				v = dp[i][k] + dp[k][j];
				if(v < dp[i][j])
					dp[i][j] = v;
			}
		}
	}
	printf("Final Algo matrix :\n");
	for(int i = 0 ; i < g.v ; i++ ) {
		for(int j = 0 ; j < g.v ; j++ ) {
			if(dp[i][j] == INF){
				printf("  INF  ");
			}
			else{
				printf("%5d  ", dp[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}