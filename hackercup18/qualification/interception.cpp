#include <bits/stdc++.h>
#define N 55

using namespace std;

int a[N];
int main() {
	int t, n, c, i;
	cin >> t;
	for(c = 1; c <= t; c++) {
		cin >> n;
		for(i = 0; i <= n; i++)
			cin >> a[i];
		cout << "Case #" << c << ": ";
		if(n % 2 == 0)
			cout << "0" << endl;
		else
			cout << "1" << endl << "0.0" << endl;
	}
	return 0;
}