#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, s, v;
	double ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &s, &v);
		ans = (2.0 * s) / (3.0 * v);
		// ans += 0.0000001;
		printf("%.12lf\n", ans);
	}
	return 0;
}