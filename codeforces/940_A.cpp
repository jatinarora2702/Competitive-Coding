#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N];

int main() {
	int n, d, m, i, x;
	scanf("%d%d", &n, &d);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	for(i = 1 ; i < N ; i++)
		a[i] += a[i-1];
	m = N;
	for(i = 1 ; i < N-d ; i++)
		m = min(m, a[i-1] + a[N-1] - a[i+d]);
	printf("%d\n", m);
	return 0;
}