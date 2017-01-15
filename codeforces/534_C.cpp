#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int lli;
int main() {
	int n, *d, k, minm, maxm;
	lli s, up, a;
	cin >> n;
	cin >> a;
	d = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	a -= n;
	s = 0;
	//cout << "a=" << a << " n=" << n << endl;
	for(int i = 0 ; i < n ; i++)
		s += ((d[i]-1) < a) ? (lli)d[i]-1 : (lli)a;
	for(int i = 0 ; i < n ; i++){
		k = ((d[i]-1) < a) ? d[i]-1 : a;
		up = s - k;
		//cout << "s=" << s << " k=" << k << " up=" << up << endl;
		if(up > a)
			minm = 0;
		else
			minm = a - up;
		maxm = (d[i]-1 < a) ? d[i]-1 : a;
		// cout << "maxm=" << maxm << " minm=" << minm << endl;
		printf("%d ", d[i] - (maxm-minm+1));
	}
	return 0;
}