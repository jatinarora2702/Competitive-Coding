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

lli exp(lli k, lli p){
	if(p == 0)
		return 1;
	if(p == 1)
		return k;
	if(p % 2 != 0)
		return k * exp(k*k, p/2);
	return exp(k*k, p/2);
}

int main(){
	int n;
	scanf("%d", &n);
	lli ans;
	ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans += exp((lli)2, (lli)i);
	}
	cout << ans << endl;
}