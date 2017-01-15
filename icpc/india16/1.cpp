#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 10005

int main() {
	int t, d, k, rem;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &d);
		k = d / 9;
		rem = d % 9;
		printf("%d\n", rem+1);
	}
	return 0;
}