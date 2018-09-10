#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, a2, h1, h2, c1, n, m;
	scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);
	n = h2 / a1 + ((h2 % a1 != 0) ? 1 : 0);
	m = max(0, (n - 1) * a2 - h1 + 1);
	m = m / (c1 - a2) + ((m % (c1 - a2) != 0) ? 1 : 0);
	printf("%d\n", m + n);
	for(int i = 0 ; i < m ; i++)
		printf("HEAL\n");
	for(int i = 0 ; i < n ; i++)
		printf("STRIKE\n");
	return 0;
}