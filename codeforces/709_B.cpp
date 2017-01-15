#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int x[N];
int main() {
	int n, a, i, pos;
	lli s1, s2, s3, s4, sm;
	scanf("%d%d", &n, &a);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &x[i]);
	}
	sort(x, x+n);
	s1 = s2 = 0LL;
	
	s1 = (lli)x[n-1] - (lli)a;
	s1 = abs(s1);
	s1 += (lli)x[n-1] - (lli)x[1];

	s3 = (lli)a - (lli)x[1];
	s3 = abs(s3);
	s3 += (lli)x[n-1] - (lli)x[1];

	s2 = (lli)a - (lli)x[0];
	s2 = abs(s2);
	s2 += (lli)x[n-2] - (lli)x[0];

	s4 = (lli)x[n-2] - (lli)a;
	s4 = abs(s4);
	s4 += (lli)x[n-2] - (lli)x[0];
	
	sm = min(s1, s2);
	sm = min(sm, s3);
	sm = min(sm, s4);

	cout << sm << endl;
	return 0;
}