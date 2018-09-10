#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

using namespace std;

typedef vector < int > vi;

const int N = 3000;
const int M = 5e6 + 5;

int dp[M];
vi p;

void findprimes() {
	int i, j;
	p.PB(2);
	for(i = 3 ; i < N ; i += 2) {
		p.PB(i);
		if (dp[i] == 0) {
			dp[i] = 1;
			for(j = i*2 ; j < N ; j += i)
				dp[j] = 1;
		}
	}
}

void findpfs() {
	int i, j, f;
	dp[0] = 0;
	dp[1] = 0;
	for(i = 2 ; i < M ; i++) {
		f = 0;
		for(j = 0 ; j < p.size() ; j++) {
			if (i % p[j] == 0) {
				dp[i] = dp[i / p[j]] + 1;
				f = 1;
				break;
			}
		}
		if (f == 0)
			dp[i] = 1;
	}
	for(i = 1 ; i < M ; i++)
		dp[i] += dp[i-1];
}

int main() {
	int a, b, t;
	findprimes();
	findpfs();
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", dp[a] - dp[b]);
	}
	return 0;
}