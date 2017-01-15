#include <bits/stdc++.h>
#define FF first
#define SS second
#define N 100005

using namespace std;
typedef long long int lli;
const int INF = 1e9+7;
const lli LONGINF = 1e18+7;

lli a[N];
map < int, int > mp;
map < int, int > :: iterator it;
int main() {
	int n, i, x, m;
	lli s, s1, t;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &x);
		mp[x]++;
	}
	i = 0;
	t = 1LL;
	while(t < LONGINF) {
		a[i] = t;
		t *= 2LL;
		i++;
	}
	m = i;
	s = 0LL;
	s1 = 0LL;
	for(i = 0 ; i < m ; i++) {
		for(it = mp.begin() ; it != mp.end() ; it++) {
			if(a[i] == 2 * it->FF) {
				t = (lli)it->SS * (lli)(it->SS - 1);
				t /= (lli)2;
				s1 += t;
			}
			else if(a[i] - it->FF >= 0 && mp.find(a[i] - it->FF) != mp.end()) {
				s += (lli)it->SS * (lli)mp[a[i] - it->FF];
			}
		}
	}
	s /= (lli)2;
	s += s1;
	cout << s << "\n";
	return 0;
}