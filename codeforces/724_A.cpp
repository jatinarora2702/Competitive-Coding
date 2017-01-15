#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005

map < string, int > mp;

int main() {
	string a, b;
	int n1, n2, n;
	mp["sunday"] = 0;
	mp["monday"] = 1;
	mp["tuesday"] = 2;
	mp["wednesday"] = 3;
	mp["thursday"] = 4;
	mp["friday"] = 5;
	mp["saturday"] = 6;
	cin >> a >> b;
	n1 = mp[a];
	n2 = mp[b];
	// printf("%d %d\n", n1, n2);
	n = (n1 + 31) % 7;
	if(n == n2) {
		printf("YES\n");
		return 0;
	}
	n = (n1 + 30) % 7;
	if(n == n2) {
		printf("YES\n");
		return 0;
	}
	n = (n1 + 28) % 7;
	if(n == n2) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}