#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define VAL 1.000000011
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;

long double exp(ld k, lli p){
	if(p == 0)
		return 1;
	if(p == 1)
		return VAL;
	if(p % 2 != 0)
		return k * exp(k*k, p/2);
	return exp(k*k, p/2);
}

int main(){
	lli n, t;
	ld p;
	cin >> n >> t;
	p = exp(VAL, t);
	p = p * (ld)n;
	cout << p << endl;
	return 0;
}