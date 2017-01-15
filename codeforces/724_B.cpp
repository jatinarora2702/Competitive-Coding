#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 25

int a[N][N], b[N], n, m;

int checkrow(int s) {
	int i, cnt;
	cnt = 0;
	for(i = 0 ; i < m ; i++) {
		if(a[s][b[i]] != i+1) {
			cnt++;
		}
	}
	// printf("s=%d | cnt=%d\n", s, cnt);
	if(cnt <= 2) {
		return 1;
	}
	return 0;
}

int check() {
	int i;
	for(i = 0 ; i < n ; i++) {
		if(!checkrow(i)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 0 ; i < m ; i++) {
		b[i] = i;
	}
	if(check()) {
		printf("YES\n");
		return 0;
	}
	for(i = 0 ; i < m ; i++) {
		for(j = i+1 ; j < m ; j++) {
			b[i] = j;
			b[j] = i;
			if(check()) {
				printf("YES\n");
				return 0;
			}
			b[i] = i;
			b[j] = j;
		}
	}
	printf("NO\n");
	return 0;
}