#include <bits/stdc++.h>
using namespace std;

set < string > v;
string ::iterator it;
int main() {
	int t, n, m, cnt1, cnt2, h, i;
	string s;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		v.clear();
		scanf("%d%d", &n, &m);
		v.insert("");
		for(i = 0 ; i < n ; i++) {
			cin >> s;
			for(it = s.begin() ; it != s.end() ; it++) {
				if(*it == '/') {
					v.insert(s.substr(0, it-s.begin()));
				}
			}
			v.insert(s);
		}
		cnt1 = v.size();
		for(i = 0 ; i < m ; i++) {
			cin >> s;
			for(it = s.begin() ; it != s.end() ; it++) {
				if(*it == '/') {
					v.insert(s.substr(0, it-s.begin()));
				}
			}
			v.insert(s);
		}
		cnt2 = v.size();
		printf("Case #%d: %d\n", h, cnt2-cnt1);
	}
	return 0;
}