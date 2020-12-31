#include<bits/stdc++.h>
#define N 500005
using namespace std;

typedef long long int lli;

const lli INF = 1e9 + 7LL;

// \sum_j (\sum_i(x_j & x_i) * \sum_k(x_j | x_k))
// for \sum_j (we have the for loop and doing explicit summation)
// for \sum_i we have the and_term, \sum_k we have the or_term
// for and_term and or_term, we are doing bit-wise addition (so, takes ~60 computations no matter how big the original array is, given every no. is <= 2^60) - awesome! so fast!

lli a[N], c[65];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int j = 0; j <= 60; j++) {
			c[j] = 0LL;
		}
		for(int i = 0; i < n; i++) {
			// cin >> a[i];	// causes time limit exceed!
			scanf("%lld", &a[i]);
			for(int j = 0; j <= 60; j++) {
				if ((1LL << j) & a[i]) {
					c[j]++;
				}
			}
		}
		lli ans = 0LL;
		for(int i = 0; i < n; i++) {
			lli and_term = 0LL;
			lli or_term = 0LL;
			for(int j = 0; j <= 60; j++) {
				if ((1LL << j) & a[i]) {
					and_term += (((1LL << j) % INF) * c[j]) % INF;
					and_term %= INF;
					or_term += (((1LL << j) % INF) * n) % INF;
					or_term %= INF;
				}
				else {
					or_term += (((1LL << j) % INF) * c[j]) % INF;
					or_term %= INF;
				}
			}
			ans += (and_term * or_term) % INF;
			ans %= INF;
		}
		printf("%lld\n", ans);
	}
	return 0;
}