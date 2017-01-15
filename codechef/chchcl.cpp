#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int t, n, m;
	lli s;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		n--;
		m--;
		s = (lli)n + ((lli)(n+1) * (lli)m);
		if(s % 2LL == 0LL)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}