#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n, m, i, x;
	x = 0;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d%d", &a, &b);
		if (x >= a && x < b)
			x = b;
	}
	if (x >= m)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}