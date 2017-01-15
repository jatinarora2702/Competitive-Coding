#include <iostream>
#include <stdio.h>
#define MIN -1000000007
using namespace std;
typedef struct{
	int x, y;
}mypair;
void pmerge(mypair *a, int m, mypair *b, int n, mypair *c) {
	int i, j, k;
	i = j = k = 0;
	while(i < m and j < n) {
		if(a[i].y < b[i].y){
			c[k].x = a[i].x;
			c[k].y = a[i].y;
			i++;
			k++;
		}
		else {
			c[k].x = b[j].x;
			c[k].y = b[j].y;
			j++;
			k++;
		}
	}
	while(i < m){
		c[k].x = a[i].x;
		c[k].y = a[i].y;
		i++;
		k++;
	}
	while(j < n){
		c[k].x = b[j].x;
		c[k].y = b[j].y;
		j++;
		k++;
	}
}
void mysort(mypair *p, int n){
	if(n <= 1)
		return;
	mypair *q;
	q = new mypair[n];
	int m = n / 2;
	mysort(p, m);
	mysort(p+m, n-m);
	pmerge(p, m, p+m, n-m, q);
	for(int i = 0 ; i < n ; i++) {
		p[i].x = q[i].x;
		p[i].y = q[i].y;
	}
}
int main() {
	int n, k, m;
	mypair *p;
	printf("Enter the no. of pairs : ");
	scanf("%d", &n);
	p = new mypair[n];
	printf("Enter the pairs in the format (x y) where x and y are both integers :\n");
	for(int i = 0 ; i < n ; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	mysort(p,n);
	m = MIN;
	k = 0;
	printf("The max. length chain is :\n");
	for(int i = 0 ; i < n ; i++) {
		if(p[i].x > m){
			m = p[i].y;
			k++;
			printf("(%d,%d) ", p[i].x, p[i].y);
		}
	}
	printf("\nMax. length of chain is : %d\n", k);
	return 0;
}