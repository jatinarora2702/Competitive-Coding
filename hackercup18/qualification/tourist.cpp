#include <bits/stdc++.h>
#define N 55

using namespace std;

typedef long long int lli;

string a[N];
int b[N];

int main() {
	int t, n, k, c, i, j;
	lli v;

	cin >> t;
	for(c = 0; c < t; c++) {
		cin >> n >> k >> v;
		for(i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = 0;
		}
		i = ((v-1) * k) % n;
		for(j = 0; j < k; j++) {
			b[i % n] = 1;
			i++;
		}
		cout << "Case #" << c+1 << ": ";
		for(i = 0; i < n; i++) {
			if(b[i] == 1)
				cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}