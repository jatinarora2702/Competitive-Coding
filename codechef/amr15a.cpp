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

#define N 105

int main() {
	int n, i, e, x;
	scanf("%d", &n);
	e = 0;
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &x);
		if(x % 2 == 0)
			e++;
	}
	if(e > n-e) {
		printf("READY FOR BATTLE\n");
	}
	else {
		printf("NOT READY\n");
	}
	return 0;
}