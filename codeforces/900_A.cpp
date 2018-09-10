#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, x, y, m;
	scanf("%d", &n);
	m = 0;
	for(i = 0 ; i < n ; i++) {
		scanf("%d%d", &x, &y);
		m += (x > 0) ? 1 : 0;
	}
	if (m <= 1 || m >= n - 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}