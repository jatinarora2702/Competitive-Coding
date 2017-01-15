#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 50
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7LL;
const lli LINF = 1e18 + 7LL;

int a[N][N], r[N], c[N], d1, d2;
int main() {
	int n, i, m, j, k, pr1, pr2, pc1, pc2;
	scanf("%d", &n);
	m = (n*n + 1) / 2;
	k = 0;
	pr1 = n/2;
	for(j = 0 ; j < n ; j++) {
		if(a[pr1][j] == 0) {
			a[pr1][j] = 2*k+1;
			k++;
		} 
	}
	for(i = 0 ; i < n ; i++) {
		if(a[i][pr1] == 0) {
			a[i][pr1] = 2*k+1;
			k++;
		} 
	}
	pr2 = pr1;
	pc1 = pc2 = pr1;
	pr1--;
	pr2++;
	while(k < m) {
		pc1--;
		pc2++;
		if(pc1 < 0) {
			pc1 = pc2 = n/2;
			pc1--;
			pc2++;
			pr1--;
			pr2++;
		}
		a[pr1][pc1] = 2*k+1;
		k++;
		a[pr1][pc2] = 2*k+1;
		k++;
		a[pr2][pc1] = 2*k+1;
		k++;
		a[pr2][pc2] = 2*k+1;
		k++;
	}
	k = 1;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			if(a[i][j] == 0) {
				a[i][j] = 2*k;
				k++;
			}
		}
	}
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}