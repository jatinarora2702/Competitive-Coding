#include <iostream>
#include <cstdio>
#define MAX 1000000
using namespace std;
typedef struct NODE{
	int v;
	struct NODE* next;
}node;
class heap {
	int *a;
	int *idx;
	int *inv_idx;
	int n;
public:
	heap(int sz, int *arr);
	void pop();
	int top();
	void modify(int element, int val);
	void print();
	int get_element(int pos);
	int get_heap_index(int element);
};
heap :: heap(int sz, int *arr) : a(new int[sz]) , idx(new int[sz]), inv_idx(new int[sz]) , n(sz) {
	for(int i = 0 ; i < n ; i++ ) {
		a[i] = MAX;
		idx[i] = i;
		inv_idx[idx[i]] = i;
	}
	for(int i = 0 ; i < n ; i++ ) {
		modify(i,arr[i]);
		print();
	}
}
int heap :: get_element(int pos) {
	return inv_idx[pos];
}
int heap :: get_heap_index(int element) {
	return idx[element];
}
void heap :: modify(int element, int val) {
	int min,pos,pos1,temp,el;
	pos = idx[element];
	a[pos] = val;
	pos1 = pos;
	while(2*pos + 1 < n) {
		min = 2*pos + 1;
		if(2*pos + 2 < n and a[min] > a[2*pos + 2]) {
			min = 2*pos + 2;
		}
		el = inv_idx[min];
		if(a[min] > a[pos]) {
			temp = a[pos];
			a[pos] = a[min];
			a[min] = temp;

			inv_idx[min] = element;
			inv_idx[pos] = el;

			idx[element] = min;
			idx[el] = pos;

			pos = min;
			element = el;
		}
		else
			break;
	}
	pos = pos1;
	while(pos > 0 and a[pos] < a[(pos-1)/2]) {
		min = (pos-1)/2;
		temp = a[pos];
		a[pos] = a[min];
		a[min] = temp;

		inv_idx[min] = element;
		inv_idx[pos] = el;

		idx[element] = min;
		idx[el] = pos;

		pos = min;
		element = el;
	}
}
void heap :: pop() {
	modify(0,MAX);
}
int heap :: top() {
	return a[0];
}
void heap :: print() {
	printf("heap is : ");
	for(int i = 0 ; i < n ; i++ ) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main() {
	int n,m,u,v,*arr,*p;
	scanf("%d%d",&n,&m);
	arr = new int[n];
	p = new int[n];
	node *g = new node[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d", &p[i]);
		g[i].v = -1;
		g[i].next = NULL;
	}
	for(int i = 0 ; i < n ; i++ ) {
		arr[i] = 0;
	}
	for(int i = 0 ; i < m ; i++ ) {
		scanf("%d%d", &u, &v);
		u--;
		v--;
		node *x = new node;
		x->v = v;
		x->next = g[u].next;
		g[u].next = x;

		x = new node;
		x->v = u;
		x->next = g[v].next;
		g[v].next = x;

		arr[u] += p[v];
		arr[v] += p[u];
	}
	for(int i = 0 ; i < n ; i++ ){ 
		
	}

	return 0;
}