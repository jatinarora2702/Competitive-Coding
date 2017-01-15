#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
int main() {
	llu n, *a, *l, *r, *sum_odd, max, sum;
	cin >> n;
	a = new llu[n];
	l = new llu[n];
	r = new llu[n];
	sum_odd = new llu[n];
	for(int i = 0 ; i < n-1 ; i++ ) {
		cin >> a[i];
	}
	l[0] = 0;
	r[n-1] = 0;
	for(int i = 1 ; i < n ; i++ ) {
		if(a[i-1] == 1) {
			l[i] = 0;
			//cout << "l[" << i << "] = " << l[i] << " ";
			continue;
		}
		l[i] = l[i-1] + (a[i-1] % 2 == 0 ? a[i-1] : a[i-1] - 1);
		//cout << "l[" << i << "] = " << l[i] << " ";
	}
	//cout << endl;
	for(int i = n-2 ; i >= 0 ; i-- ) {
		r[i] = r[i+1] + (a[i] % 2 == 0 ? a[i] : a[i] - 1);
		//cout << "r[" << i << "] = " << r[i] << " ";
	}
	//cout << endl;
	sum_odd[0] = 0;
	for(int i = 1 ; i < n ; i++ ) {
		sum_odd[i] = sum_odd[i-1] + (a[i-1] % 2 != 0 ? a[i-1] : a[i-1] - 1);
		//cout << "sum_odd[" << i << "] = " << sum_odd[i] << " ";
	}
	max = 0;
	sum = sum_odd[0] + r[0] + l[max] - sum_odd[max];
	for(int i = 1 ; i < n ; i++ ) {
		if(l[max] - sum_odd[max] < l[i] - sum_odd[i]) {
			max = i - 1;
			if(sum < sum_odd[i] + r[i] + l[max] - sum_odd[max]) {
				sum = sum_odd[i] + r[i] + l[max] - sum_odd[max];
			}
		}
	}
	cout << sum;
	return 0;
}