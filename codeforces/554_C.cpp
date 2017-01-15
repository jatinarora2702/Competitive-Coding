#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef unsigned long long int ulli;
ulli ncr(int n, int r){
	//cout << n << " " << r << " p" << endl;
	ulli s1, s2;
	if(r == 0)
		return 1;
	s1 = n; s2 = r;
	for(int i = 1 ; i < r; i++){
		s1 *= (ulli)(n-i);
		//s1 %= (ulli)MOD;
		s2 *= (ulli)(r-i);
		//s2 %= (ulli)MOD;
	}
	ulli tmp = s1 / s2;
	tmp %= (ulli)MOD;
	return tmp;
}
int main(){
	int n, *c;
	ulli sum , tmp, tot;
	scanf("%d", &n);
	c = new int[n];
	tot = 0;
	for(int i = 0 ; i <  n ; i++){
		scanf("%d", &c[i]);
		tot += (ulli)c[i];
	}
	//cout << tot << endl;
	sum = 1;
	for(int i = n-1 ; i >= 0 ; i--){
		tmp = ncr((tot-1),c[i]-1);
		//cout << tmp << endl;
		tot = tot - (ulli)c[i];
		sum *= tmp;
		sum %= (ulli)MOD; 
	}
	cout << sum;
	return 0;
}