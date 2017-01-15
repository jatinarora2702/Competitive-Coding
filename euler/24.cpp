#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
int fact(int n) {
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	return n * fact(n-1);
}

void getseq(int n, int k) {
	// printf("(%d, %d)->", n, k);
	int p, f, i, j;
	if(n < 0 || k >= 10)
		return;
	p = fact(9-k);
	f = n / p;
	if(n == f*p && n > 0)
		f--;
	n -= f*p;
	j = 0;
	for(i = 0 ; i < 10 ; i++) {
		if(a[i] == 0) {
			if(j == f) {
				b[k] = i;
				// printf("%d", i);
				a[i] = 1;
				break;
			}
			else
				j++;
		}
	}
	// printf("\n");
	getseq(n, k+1);
}

int main() {
	int i, n;
	scanf("%d", &n);
	getseq(n, 0);
	for(i = 0 ; i < 10 ; i++) {
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}