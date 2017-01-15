#include <bits/stdc++.h>
#define N 105
using namespace std;

// Very Important for diagonal matrix traversals!!!!!!!!!!!

int a[N][N];
int main() {
	int n, m, d, i, j, D;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	D = m + n - 1;
	for(d = 0 ; d < D ; d++) {
		for(i = 0 ; i < n ; i++) {
			if(d-i >= 0 && d-i < m) {
				printf("%d ", a[i][d-i]);
			}
		}
		printf("\n");
	}
	printf("-------------------------\n");
	for(d = 0 ; d < D ; d++) {
		for(i = n-1 ; i >= 0 ; i--) {
			if(d-i >= 0 && d-i < m) {
				printf("%d ", a[i][d-i]);
			}
		}
		printf("\n");
	}
	printf("-------------------------\n");
	for(d = 0 ; d < D ; d++) {
		for(i = 0 ; i < n ; i++) {
			if(d-i >= 0 && d-i < m) {
				printf("%d ", a[n-i-1][m-(d-i)-1]);
			}
		}
		printf("\n");
	}
	printf("-------------------------\n");
	for(d = 0 ; d < D ; d++) {
		for(i = 0 ; i < n ; i++) {
			if(d-i >= 0 && d-i < m) {
				printf("%d ", a[n-i-1][d-i]);
			}
		}
		printf("\n");
	}
	printf("-------------------------\n");
	for(d = 0 ; d < D ; d++) {
		for(i = 0 ; i < n ; i++) {
			if(d-i >= 0 && d-i < m) {
				printf("%d ", a[i][m-(d-i)-1]);
			}
		}
		printf("\n");
	}
	return 0;
}