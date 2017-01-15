#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
typedef struct EDGE_NODE{
	int y, w;
	struct EDGE_NODE *next;
}edge_node;
typedef struct{
	int num, dist;
}queue_node;
class priority_queue{
public:
	int len;
	int *hidx;
	queue_node *arr;
	priority_queue(int v, int s) : len(v) {
		arr = new queue_node[v];
		hidx = new int[v];
		for(int i = 0 ; i < v ; i++){
			hidx[i] = i;
			arr[i].num = i;
			arr[i].dist = INF;
		}
		hidx[0] = s;
		hidx[s] = 0;
		arr[s].num = 0;
		arr[0].num = s;
		arr[0].dist = 0;
	}
	int modify(int node_num, int new_val);
	void pop();
};
int priority_queue::modify(int node_num, int new_val) {
	int i;
	queue_node temp;
	i = hidx[node_num];
	if(arr[i].dist > new_val){
		arr[i].dist = new_val;
		while(true){
			if((i-1)/2 >= 0 and arr[i].dist < arr[(i-1)/2].dist){
				hidx[arr[i].num] = (i-1)/2;
				hidx[arr[(i-1)/2].num] = i;
				temp = arr[i];
				arr[i] = arr[(i-1)/2];
				arr[(i-1)/2] = temp;
				i = (i-1)/2;
			}
			else
				break;
		}
		return 1;	
	}
	else
		return 0;
}
void priority_queue::pop(){
	queue_node temp;
	int i, min;
	if(len <= 1){
		len = 0;
		return;
	}
	hidx[arr[0].num] = len-1;
	hidx[arr[len-1].num] = 0;
	temp = arr[0];
	arr[0] = arr[len-1];
	arr[len-1] = temp;
	len--;
	i = 0;
	while(true){
		if((2*i+1) < len and arr[i].dist > arr[2*i+1].dist){
			min = 2*i+1;
			if(min+1 < len and arr[min].dist > arr[min+1].dist)
				min++;
			hidx[arr[min].num] = i;
			hidx[arr[i].num] = min;
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		else
			break;
	}
}
class graph{
	int v, f;
	edge_node *adj;
public:
	graph(int v_, int f_);
	void add_edge(int x, int y, int w);
	void dijkstra(int s);
};
graph::graph(int v_, int f_) : v(v_), f(f_) {
	adj = new edge_node [v];
	for(int i = 0 ; i < v ; i++){
		adj[i].y = -1;
		adj[i].next = NULL;
	}
}
void graph::add_edge(int x, int y, int w) {
	edge_node *en;
	en = new edge_node;
	en->y = y;
	en->w = w;
	en->next = adj[x].next;
	adj[x].next = en;
	if(f == 1){
		en = new edge_node;
		en->y = x;
		en->w = w;
		en->next = adj[y].next;
		adj[y].next = en;
	}
}

void graph::dijkstra(int s){
	int k,f;
	k = 0;
	queue_node qn;
	edge_node *x;
	int *ingraph = new int[v];
	int *d = new int[v];
	int *p = new int[v];
	p[s] = -1;
	priority_queue pq(v,s);
	while(k < v){
		qn = pq.arr[0];
		d[qn.num] = qn.dist;
		ingraph[pq.arr[0].num] = 1;
		pq.pop();
		x = adj[qn.num].next;
		while(x != NULL){
			if(ingraph[x->y] == 0){
				f = pq.modify(x->y, x->w + qn.dist);
				if(f == 1){
					p[x->y] = qn.num;
				}	
			}
			x = x->next;
		}
		k++;
	}
	printf("Dijkstra :\nd : ");
	for(int i = 0 ; i < v ; i++){
		printf("%3d ", d[i]);
	}
	printf("\np : ");
	for(int i = 0 ; i < v ; i++){
		printf("%3d ", p[i]);
	}
	printf("\n");
}
int main() {
	int v, e, x, y, w, f, s;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &v, &e);
	printf("Is the graph directed(0) or undirected(1) : ");
	scanf("%d", &f);
	graph g(v,f);
	printf("Enter the graph edges (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g.add_edge(x,y,w);
	}
	printf("Enter the source vertex for dijkstra : ");
	scanf("%d", &s);
	g.dijkstra(s);
	return 0;
}