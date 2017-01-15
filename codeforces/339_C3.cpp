#include <bits/stdc++.h>
#define N 1005
#define M 15
using namespace std;

int a[M], b[N], m, f;

void dfs_visit(int w, int p, int n) {
	int i;
	for(i = 1 ; i <= 10 ; i++) {
		if(a[i] == 1 && i > w && i != p && f == 0) {
			b[n] = i;
			if(n == m-1) {
				f = 1;
				return;
			}
			dfs_visit(i-w, i, n+1);
		}
	}
}

int main() {
	int i;
	char s[M];
	f = 0;
	scanf("%s%d", s, &m);
	for(i = 0 ; s[i] != '\0' ; i++) {
		a[i+1] = s[i] - '0';
	}
	dfs_visit(0, 0, 0);	
	if(f == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		for(i = 0 ; i < m ; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}