#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int main() {
	int t, s1, s2, temp;
	double ans, w, h;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &s1, &s2);
		if(s1 < s2) {
			temp = s1;
			s1 = s2;
			s2 = temp;
		}
		w = max((double)s1, (s1+2*s2)/2.0);
		h = (s1*sqrt(3))/2.0;
		ans = w * h;
		printf("%.3lf\n", ans);
	}
	return 0;
}