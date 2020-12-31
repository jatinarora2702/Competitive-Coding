#include <bits/stdc++.h>
#define N 200005

using namespace std;

int a[N];
int main() {
	int t, n, cnt, minm;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cnt = 0;
		minm = a[n-1];
		for(int i = n-2; i >= 0; i--) {
			if (a[i] > minm) {
				cnt++;
			}
			if (a[i] < minm) {
				minm = a[i];
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}