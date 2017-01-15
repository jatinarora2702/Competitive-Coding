#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct{
	int v, m;
}node;
int allocate_manager(node *p, int s){
	//cout << "r\n";
	if(p[s].m == -1)
		p[s].m = 1 + allocate_manager(p, p[s].v);
	return p[s].m;
}
int main() {
	int n, max, k;
	node *p;
	scanf("%d", &n);
	p = new node[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &p[i].v);
		if(p[i].v != -1)
			p[i].v -= 1;
		p[i].m = -1;
		if(p[i].v == -1)
			p[i].m = 1;
	}
	max = 0;
	for(int i = 0 ; i < n ; i++){
		k = allocate_manager(p,i);
		if(k > max)
			max = k;
	}
	printf("%d", max);
	return 0;
}