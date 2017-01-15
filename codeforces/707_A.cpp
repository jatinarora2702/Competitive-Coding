#include <bits/stdc++.h>
using namespace std;

char a[105][105];
int main() {
	int n, m, f, i, j;
	scanf("%d%d", &n, &m);
	f = 0;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			scanf(" %c", &a[i][j]);
			// printf("[%c]\n", a[i][j]);
			if(!(a[i][j] == 'W' || a[i][j] == 'B' || a[i][j] == 'G')) {
				f = 1;
			}
		}
	}
	if(f ==0) {
		printf("#Black&White\n");
	}
	else {
		printf("#Color\n");
	}
	return 0;
}