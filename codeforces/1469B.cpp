#include<bits/stdc++.h>
#define N 105

using namespace std;

int r[N], b[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> r[i];
		}
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int pr, pb, fr, fb;
		pr = pb = fr = fb = 0;
		for(int i = 0; i < n; i++) {
			pr += r[i];
			fr = max(fr, pr);
		}
		for(int i = 0; i < m; i++) {
			pb += b[i];
			fb = max(fb, pb);
		}
		cout << (fr + fb) << "\n";
	}
	return 0;
}
