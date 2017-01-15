#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[N];

int part(int *a, int n) {
	int f, l, temp;
	f = 1;
	l = n-1;
	while(f < l) {
		while(a[f] < a[0] && f < n) {
			f++;
		}
		while(a[l] >= a[0] && l >= 0) {
			l--;
		}
		if(f < l) {
			temp = a[f];
			a[f] = a[l];
			a[l] = temp;
			f++;
			l--;
		}
		else {
			break;
		}
	}
	f--;
	if(f < n) {
		temp = a[0];
		a[0] = a[f];
		a[f] = temp;
	}
	return f;
}

void qsort(int *a, int n) {
	if(n <= 1)
		return;
	int k;
	k = part(a, n);
	qsort(a, k);
	qsort(a+k+1, n-k-1);
}

int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n);
	for(i = 0 ; i < n ; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}