#include <bits/stdc++.h>
#define N 65
using namespace std;
typedef long long int lli;
lli a[N];
int main(){
	int k1, k2, pos;
	lli k, l, r, cnt, v;
	k = 2;
	for(int i = 1 ; i < 61 ; i++){
		a[i] = k - (lli)1;
		// cout << a[i] << endl;
		k *= (lli)2;
		// cout << k << endl;
	}
	// cout << a[60] << endl;
	cin >> l >> r;
	k1 = lower_bound(a, a+61, l) - a;
	// cout << "k1=" << k1 << endl;
	k2 = lower_bound(a, a+61, r) - a;
	// cout << "k2=" << k2 << endl;
	cnt = 0;
	if(k1 == k2){
		v = a[k1] - (lli)1;
		pos = 0;
		while(v >= l){
			if(v <= r)
				cnt++;
			v += ((lli)1 << (lli)pos);
			pos++;
			v -= ((lli)1 << (lli)pos);
		}
	}
	else{
		v = a[k1] - (lli)1;
		pos = 0;
		while(v >= l){
			if(v <= r)
				cnt++;
			v += ((lli)1 << (lli)pos);
			pos++;
			v -= ((lli)1 << (lli)pos);
		}
		// cout << "cnt1=" << cnt << endl;
		v = a[k2]-1;
		pos = 0;
		while(v > a[k2-1]){
			// cout << v << endl;
			if(v <= r && v >= l)
				cnt++;
			v += ((lli)1 << (lli)pos);
			pos++;
			v -= ((lli)1 << (lli)pos);	
		}
		// cout << "cnt2=" << cnt << endl;
		for(int i = k1+1 ; i < k2 ; i++){
			cnt += (lli)(i-1);
		}
	}	
	cout << cnt;
	return 0;
}