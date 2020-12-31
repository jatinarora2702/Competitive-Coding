#include<bits/stdc++.h>
#define N 105
using namespace std;


int a[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		set<int> st;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				st.insert(a[j] - a[i]);
			}
		}
		cout << st.size() << "\n";
	}
	return 0;
}