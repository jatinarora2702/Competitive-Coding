#include<bits/stdc++.h>
#define N 200005

using namespace std;

int dpmax[N], dpmin[N], h[N];

int main() {
	int t;
	int n, k, f;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> h[i];
		}
		f = 1;
		dpmax[0] = dpmin[0] = h[0] + k;
		for(int i = 1; i < n; i++) {
			dpmax[i] = min(dpmax[i-1] + k - 1, h[i] + 2*k - 1);
			dpmin[i] = max(dpmin[i-1] - k + 1, h[i] + k);
			// cout << "max: " << dpmax[i] << " min: " << dpmin[i] << "\n";
			if (dpmax[i] < dpmin[i]) {
				f = 0;
				break;
			}
		}
		if ((dpmax[n-1] >= (h[n-1] + k)) && (dpmin[n-1] <= (h[n-1] + k)) && (f == 1)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}