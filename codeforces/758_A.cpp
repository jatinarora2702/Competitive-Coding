#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 10005

int a[N];
int main() {
	int n, i, m, s;
	scanf("%d", &n);
	m = 0;
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}
	s = 0;
	for(i = 0 ; i < n ; i++) {
		s += m - a[i];
	}
	printf("%d\n", s);
	return 0;
}