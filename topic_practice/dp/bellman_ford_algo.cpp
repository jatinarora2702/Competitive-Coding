#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
typedef struct NODE{
	int x, wt;
	struct NODE *next;
}node;
typedef struct{
	int v, e;
	node *adjlist;
}graph;
int main() {
	int x, y, z, f, src, *dp, neg;
	graph g;
	node *n;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &g.v, &g.e);
	printf("Is the graph directed(1) or undirected(0) : ");
	scanf("%d", &f);
	printf("Enter the edges of the graph in format (u v w) :\n");
	g.adjlist = new node[g.v];
	for(int i = 0 ; i < g.v ; i++) {
		g.adjlist[i].x = 0;
		g.adjlist[i].wt = 0;
		g.adjlist[i].next = NULL;
	}
	for(int i = 0 ; i < g.e ; i++){
		n = new node;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		n->x = y;
		n->wt = z;
		n->next = g.adjlist[x].next;
		g.adjlist[x].next = n;
		if(f == 0){
			n = new node;
			n->next = g.adjlist[y].next;
			n->x = x;
			n->wt = z;
			g.adjlist[y].next = n;
		}
	}
	printf("Enter the index of the source vertex : ");
	scanf("%d", &src);
	dp = new int[g.v];
	dp[src-1] = 0;
	for(int i = 0 ; i < g.v ; i++)
		if(i != src-1)
			dp[i] = INF;
	for(int j = 0 ; j < g.v-1 ; j++){
		for(int i = 0 ; i < g.v ; i++){
			n = g.adjlist[i].next;
			while(n != NULL){
				if(dp[n->x] > dp[i] + n->wt)
					dp[n->x] = dp[i] + n->wt;
				n = n->next;
			}
		}
	}
	neg = 0;
	for(int i = 0 ; i < g.v ; i++) {
		n = g.adjlist[i].next;
		while(n != NULL) {
			if(dp[n->x] > dp[i] + n->wt){
				dp[n->x] = dp[i] + n->wt;
				neg = 1;
				break;
			}
			n = n->next;
		}
		if(neg == 1)
			break;
	}
	if(neg == 1)
		printf("The graph has a neg. wt. cycle\n");
	else{
		printf("The shortest distances to various vertices from source is :\n");
		for(int i = 0 ; i < g.v - 1 ; i++) {
			printf("%d : %d | ", i+1, dp[i]);
		}
		printf("%d : %d\n", g.v, dp[g.v - 1]);
	}
	return 0;
}