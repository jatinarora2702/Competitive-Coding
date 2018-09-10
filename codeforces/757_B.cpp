#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 100001

int a[N], b[N];
int main() {
	int n, i, maxm, s, k, j;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &k);
		a[k]++;
	}
	maxm = 0;
	if(a[1] > 0)
		maxm = 1;
	for(i = 2 ; i < N ; i++) {
		if(b[i] == 0) {
			s = 0;
			for(j = i ; j < N ; j+=i) {
				s += a[j];
				b[j] = 1;
			}
			maxm = max(maxm, s);
		}
	}
	printf("%d\n", maxm);
	return 0;
}