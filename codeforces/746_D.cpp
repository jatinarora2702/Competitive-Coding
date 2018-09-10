#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, a[2], d, r, f, i, j;
	char b[2];
	b[0] = 'G';
	b[1] = 'B';
	scanf("%d%d%d%d", &n, &k, &a[0], &a[1]);
	f = (a[0] >= a[1]) ? 0 : 1;
	d = max(a[0], a[1]) / (min(a[0], a[1]) + 1);
	r = max(a[0], a[1]) % (min(a[0], a[1]) + 1);
	if (d < k || (d == k && r == 0)) {
		j = 0;
		for(i = 0 ; i < n ; i++) {
			if (j < d) {
				printf("%c", b[f]);
				j++;
			}
			else if (j == d) {
				if (r > 0) {
					printf("%c", b[f]);
					i++;
					r--;
				}
				printf("%c", b[f^1]);
				j = 0;
			}
		}
		printf("\n");
	}
	else
		printf("NO\n");
	return 0;
}