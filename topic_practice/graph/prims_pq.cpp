#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
typedef struct MYPAIR{
	int v, w;
	struct MYPAIR *next;
}mypair;
class graph{
	int n;
	mypair *adj;
public:
	graph(int n_);
	void add_edge(int u, int v, int w);
	void printg();
	void prims();
};
class pq_node{
public:
	int dist, idx;
	pq_node(){
		static int cnt = -1;
		dist = INF;
		idx = cnt;
		cnt++;
	}
};
class priorityq{
public:
	pq_node *arr;
	int len;
	int *hidx;
	priorityq(int n) : len(n) {
		arr = new pq_node[n];
		hidx = new int[n];
		for(int i = 0 ; i < len ; i++)
			hidx[i] = i;
	}
	pq_node getp() {
		return arr[0];
	}
	void pop();
	int modify(int idx, int new_val);
};
void priorityq::pop() {
	int min, i;
	i = 0;
	pq_node temp;
	hidx[arr[0].idx] = len-1;
	hidx[arr[len-1].idx] = 0;
	temp = arr[0];
	arr[0] = arr[len-1];
	arr[len-1] = temp;
	len--;
	while(true){
		if(2*i+1 < len and arr[2*i+1].dist < arr[i].dist){
			min = 2*i+1;
			if(min+1 < len and arr[min+1].dist < arr[min].dist){
				min++;
			}
			hidx[arr[i].idx] = min;
			hidx[arr[min].idx] = i;
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			i = min;
		}
		else
			break;
	}
}
int priorityq::modify(int idx, int new_val){
	cout << "neww" << new_val << endl;
	pq_node temp;
	int i = hidx[idx];
	cout << "idx=" << i << endl;
	if(arr[i].dist > new_val){
		arr[i].dist = new_val;
		printf("po : ");
		for(int ix = 0 ; ix < len ; ix++){
			printf("%12d(%d) ", arr[ix].dist, arr[ix].idx);
		}
		printf("\n");
		while(true){
			if((i-1)/2 >= 0 and arr[i].dist < arr[(i-1)/2].dist){
				hidx[idx] = (i-1)/2;
				hidx[arr[(i-1)/2].idx] = i;
				temp = arr[i];
				arr[i] = arr[(i-1)/2];
				arr[(i-1)/2] = temp;
				i = (i-1)/2;
				printf("ps : ");
				for(int ix = 0 ; ix < len ; ix++){
					printf("%12d(%d) ", arr[ix].dist, arr[ix].idx);
				}
				printf("\n");
			}
			else
				break;
		}
		return 1;
	}
	else
		return 0;
}
graph::graph(int n_) : n(n_) {
	adj = new mypair[n];
	for(int i = 0 ; i < n ; i++){
		adj[i].v = adj[i].w = 0;
		adj[i].next = NULL;
	}
}
void graph::add_edge(int u, int v, int w) {
	mypair *p = new mypair;
	p->v = v;
	p->w = w;
	p->next = adj[u].next;
	adj[u].next = p;
	p = new mypair;
	p->v = u;
	p->w = w;
	p->next = adj[v].next;
	adj[v].next = p;
}
void graph::prims(){
	int k, f;
	k = 0;
	int *p = new int[n];
	int *d = new int[n];
	int *ingraph = new int[n];
	pq_node pqn;
	mypair *x;
	priorityq pq(n);
	printf("pq : ");
		for(int i = 0 ; i < pq.len ; i++){
			printf("%12d(%d) ", pq.arr[i].dist, pq.arr[i].idx);
		}
		printf("done\n");
	for(int i = 0 ; i < n ; i++){
		p[i] = -1;
	}
	pq.arr[0].dist = 0;
	while(k < n){
		printf("pq : ");
		for(int i = 0 ; i < pq.len ; i++){
			printf("%12d(%d) ", pq.arr[i].dist, pq.arr[i].idx);
		}
		printf("\n");
		pqn = pq.getp();
		pq.pop();
		ingraph[pqn.idx] = 1;
		printf("pp : ");
		for(int i = 0 ; i < pq.len ; i++){
			printf("%12d(%d) ", pq.arr[i].dist, pq.arr[i].idx);
		}
		printf("\n");
		d[pqn.idx] = pqn.dist;
		x = adj[pqn.idx].next;
		while(x != NULL){
			if(ingraph[x->v] == 0){
				cout << "going : \n";
				f = pq.modify(x->v, x->w);
				printf("pm : ");
				for(int i = 0 ; i < pq.len ; i++){
					printf("%12d(%d) ", pq.arr[i].dist, pq.arr[i].idx);
				}
				printf("\n");
				if(f == 1){
					p[x->v] = pqn.idx;
				}
			}
			x = x->next;
		}
		k++;
	}
	printf("Prims :\n");
	for(int i = 0 ; i < n ; i++){
		printf("d[%d] = %d ", i, d[i]);
	}
	printf("\n");
	for(int i = 0 ; i < n ; i++){
		printf("p[%d] = %d ", i, p[i]);
	}
	printf("\n");
}
void graph::printg(){
	mypair *x;
	printf("printing graph\n");
	for(int i = 0 ; i < n ; i++){
		printf("%d : ", i);
		x = adj[i].next;
		while(x != NULL){
			printf("%d(%d) ", x->v, x->w);
			x = x->next;
		}
		printf("\n");
	}
	printf("printed\n");
}
int main(){
	int n, e, u, v, w;
	printf("Enter the no. of vertices and edges int the graph (v e) : ");
	scanf("%d%d", &n, &e);
	graph g(n);
	printf("Enter the graph edges (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &u, &v, &w);
		g.add_edge(u, v, w);
	}
	g.printg();
	g.prims();
	return 0;
}