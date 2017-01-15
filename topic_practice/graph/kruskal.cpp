#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
typedef struct{
	int x, y, w;
}node;
typedef struct{
	int p, r;
}myset;
class graph{
	int v,e;
	node *arr;
public:
	graph(int v_, int e_);
	void add_edge(int x, int y, int w);
	void kruskals();
};
void merges(node *a, int m, node *b, int n, node *c){
	int i, j, k;
	i = j = k = 0;
	while(i < m and j < n){
		if(a[i].w < b[j].w) c[k++] = a[i++];
		else c[k++] = b[j++];
	}
	while(i < m) c[k++] = a[i++];
	while(j < n) c[k++] = b[j++];
}
void merge_sort(node *a, int n){
	if(n == 1 or n == 0)
		return;
	int m;
	node *b = new node[n];
	m = n/2;
	merge_sort(a,m);
	merge_sort(a+m, n-m);
	merges(a,m,a+m,n-m,b);
	for(int i = 0 ; i < n ; i++)
		a[i] = b[i];
}
myset* makeset(int n){
	myset *s = new myset[n];
	for(int i = 0 ; i < n ; i++){
		s[i].p = i;
		s[i].r = 0;
	}
	return s;
}
int findset(myset* s, int i){
	if(i == s[i].p)
		return i;
	s[i].p = findset(s, s[i].p);
}
void unionsets(myset*s, int i, int j){
	int r1 = findset(s, i);
	int r2 = findset(s, j);
	if(r1 != r2){
		if(s[r1].r < s[r2].r)
			s[r1].p = r2;
		else if(s[r1].r > s[r2].r)
			s[r2].p = r1;
		else{
			s[r2].p = r1;
			s[r1].r++;
		}
	}
}
graph::graph(int v_, int e_) : v(v_), e(e_) {
	arr = new node[e];
}
void graph::add_edge(int x, int y, int w) {
	static int cnt = 0;
	arr[cnt].x = x;
	arr[cnt].y = y;
	arr[cnt].w = w;
	cnt++;
}
void graph::kruskals() {
	int *p = new int[v];
	for(int i = 0 ; i < v ; i++)
		p[i] = -1;
	merge_sort(arr,e);
	myset *s = makeset(v);
	list < node > lst;
	for(int i = 0 ; i < e ; i++){
		int r1 = findset(s,arr[i].x);
		int r2 = findset(s,arr[i].y);
		if(r1 != r2){
			lst.push_back(arr[i]);
		}
		unionsets(s,r1,r2);
	}
	for(typeof(lst.begin()) it = lst.begin() ; it != lst.end() ; it++){
		printf("(%d,%d)%d ", (*it).x, (*it).y, (*it).w);
	}
	printf("\n");
}
int main() {
	int n, e, u, v, w;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	graph g(n,e);
	printf("Enter the edges (u v w) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &u, &v, &w);
		g.add_edge(u,v,w);
	}
	g.kruskals();
	return 0;
}