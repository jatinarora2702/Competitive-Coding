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
	int n, i, m, j, k, posr, posc, fr, fc;
	scanf("%d", &n);
	m = (n*n + 1) / 2;
	k = 0;
	while(k < m) {
		fr = 0;
		for(i = 0 ; i < n; i++) {
			if(r[i] % 2 == 0) {
				fr = 1;
				posr = i;
				r[i]++;
				break;
			}
		}
		if(fr == 0) {
			for(i = 0 ; i < n ; i++) {
				if(r[i] < n) {
					fr = 1;
					r[i]++;
					posr = i;
					break;
				}
			}
		}
		fc = 0;
		for(j = 0 ; j < n ; j++) {
			if(c[j] % 2 == 0) {
				posc = j;
				c[j]++;
				fc = 1;
				a[posr][posc] = 2*k+1;
				break;
			}
		}
		if(fc == 0) {
			for(j = 0 ; j < n ; j++) {
				if(c[j] < n) {
					posc = j;
					c[j]++;
					fc = 1;
					a[posr][posc] = 2*k+1;
					break;
				}
			}	
		}
		printf("(%d, %d) -> %d\n", posr, posc, 2*k+1);
		k++;
	}
	k = 1;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			if(a[i] == 0) {
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