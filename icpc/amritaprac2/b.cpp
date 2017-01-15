#include <bits/stdc++.h>
#define N 100005
using namespace std;

int a[N], b[N], c[N];
int main() {
	int t, n, k, k1, i, j, d, f, m;
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
		d = n / k;
		f = n % k;
		// printf("d=%d | f=%d\n", d, f);
		if(d % 2 == 0 && f == 0) {
			m = d;
		}
		else if(d % 2 == 0 && f > 0) {
			m = d - 2;
		}
		else if(d % 2 == 1 && f == 0) {
			m = d - 3;
		}
		else if(d % 2 == 1 && f > 0) {
			m = d - 3;
		}
		// printf("m=%d\n", m);
		for(i = 0 ; i < m ; i+=2) {
			for(j = 0 ; j < k ; j++) {
				a[i*k+j] = i*k+j+k+1;
				a[i*k+k+j] = i*k+j+1;
			}
		}
		j = 0;
		for(i = m*k ; i < n ; i++) {
			// printf("i=%d | j=%d\n", i, j);
			b[j] = i+1;
			// printf("[%d] ", b[j]);
			j++;
		}
		// printf("\n");
		// printf("j=%d\n", j);
		for(i = 0 ; i < j ; i++) {
			k1 = (i+k) % j;
			// printf("k2=%d\n", k1);
			// if(k1 < 0) {
			// 	k1 = j + k1;
			// }
			// printf("k1=%d\n", k1);
			c[i] = b[k1];
		}
		j = 0;
		for(i = m*k ; i < n ; i++) {
			a[i] = c[j];
			j++;
		}
		for(i = 0 ; i < n ; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}