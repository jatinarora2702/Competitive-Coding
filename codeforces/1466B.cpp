#include<bits/stdc++.h>
#define N 200005
using namespace std;

int a[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n;
		for(int i = 0; i <= 2*n+1; i++) {
			a[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
		}
		for(int i = 0; i <= 2*n; i++) {
			if (a[i] > 1) {
				a[i]--;
				a[i+1]++;
			}
		}
		int m = 0;
		for(int i = 0; i <= 2*n+1; i++) {
			if (a[i] > 0) {
				m++;
			}
		}
		cout << m << "\n";
	}
	return 0;
}