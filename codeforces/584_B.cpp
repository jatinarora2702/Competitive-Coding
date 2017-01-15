#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli MOD = 1e9+7;
int main(){
	int n, p, p1;
	lli k, k1, v, v1;
	scanf("%d", &n);
	k = 3 * (lli)n;
	p = 1;
	v = 3;
	while(p*2 < k){
		v *= v;
		v %= MOD;
		p *= 2;
	}
	while(p < k){
		v *= 3;
		v %= MOD;
		p++;
	}
	k1 = (lli)n;
	p1 = 1;
	v1 = 7;
	while(p1*2 < k1){
		v1 *= v1;
		v1 %= MOD;
		p1 *= 2;
	}
	while(p1 < k1){
		v1 *= 7;
		v1 %= MOD;
		p1++;
	}
	v -= v1;
	while(v < 0)
		v += MOD;
	v %= MOD;
	cout << v;
	return 0;
}