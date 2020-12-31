#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

using namespace std;

typedef pair<int, int> pii;

vector<pii> vp;

int main() {
	int t, n, m, s;
	cin >> t;
	while(t--) {
		cin >> n;
		vp.clear();
		s = 0;
		while(n > 2) {
			m = ceil(sqrt(n));
			for(int i = m+1; i < n; i++) {
				vp.PB(MP(i, i+1));
				s++;
			}
			vp.PB(MP(n, m));
			vp.PB(MP(n, m));
			s += 2;
			n = m;
		}
		cout << s << "\n";
		for(int i = 0; i < vp.size(); i++) {
			cout << vp[i].FF << " " << vp[i].SS << "\n";
		}
	}
	return 0;
}