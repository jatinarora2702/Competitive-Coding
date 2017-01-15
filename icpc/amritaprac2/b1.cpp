#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[N];
int main() {
	int t, n, k, l, m, temp, d, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		if(k > n/2) {
			printf("-1\n");
			continue;
		}
		else if(k == 0) {
			for(i = 0 ; i < n ; i++) {
				printf("%d ", i+1);
			}
			printf("\n");
			continue;
		}
		m = 2*k;
		d = n / m;
		for(i = 0 ; i < n ; i++) {
			a[i] = i+1;
		}
		for(i = 0 ; i < d ; i++) {
			l = i*2*k;
			for(j = 0 ; j < k ; j++) {
				// printf("(%d, %d) ", l+j, l+k+j);
				temp = a[l+k+j];
				a[l+k+j] = a[l+j];
				a[l+j] = temp;
			}
		}
		sort(a+n-m, a+n);
		for(j = 0 ; j < k ; j++) {
			temp = a[n-1-j];
			a[n-1-j] = a[n-1-j-k];
			a[n-1-j-k] = temp;
		}
		for(i = 0 ; i < n ; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}