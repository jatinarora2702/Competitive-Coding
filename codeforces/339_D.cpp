#include <bits/stdc++.h>
using namespace std;

const int N = 140000;

int a[N][19];

int main() {
	int n, m, i, j, k, p, b, n1;
	scanf("%d%d", &n, &m);
	n1 = 1;
	for(i = 0 ; i < n ; i++)
		n1 *= 2;
	for(i = 0 ; i < n1 ; i++)
		scanf("%d", &a[i][0]);
	k = 1;
	for(i = 1 ; i <= n ; i++) {
		for(j = 0 ; j < n1-k ; j += k*2)
			a[j][i] = (i % 2 == 1) ? (a[j][i-1] | a[j+k][i-1]) : (a[j][i-1] ^ a[j+k][i-1]);
		k *= 2;
	}
	for(j = 0 ; j < m ; j++) {
		scanf("%d%d", &p, &b);
		p--;
		a[p][0] = b;
		k = 1;
		for(i = 1 ; i <= n ; i++) {
			if (p % (k * 2) == 0) {
				a[p][i] = (i % 2 == 1) ? (a[p][i-1] | a[p+k][i-1]) : (a[p][i-1] ^ a[p+k][i-1]);
			}
			else if (p % (k * 2) == k) {
				a[p-k][i] = (i % 2 == 1) ? (a[p-k][i-1] | a[p][i-1]) : (a[p-k][i-1] ^ a[p][i-1]);
				p -= k;
			}
			k *= 2;
		}
		printf("%d\n", a[p][n]);
	}
	return 0;
}