#include <bits/stdc++.h>
using namespace std;

map < string, int > mp;
int main() {
	int n, m, a[2], c, f, i;
	string s;
	scanf("%d%d", &n, &m);
	a[0] = a[1] = c = 0;
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		mp[s] = 1;
		a[0]++;
	}
	for(i = 0 ; i < m ; i++) {
		cin >> s;
		if(mp.find(s) != mp.end()) {
			c++;
			a[0]--;
		}
		else
			a[1]++;
	}
	f = c % 2;
	f = (a[f] > a[f^1]) ? f : f^1;
	(f == 0) ? printf("YES\n") : printf("NO\n");
	return 0;
}