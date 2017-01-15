#include <bits/stdc++.h>
#define N 100005
#define M 10000005
using namespace std;
typedef long long int lli;
lli p[N], fact[M], m;
int main(){
	int n;
	lli ans, temp1, temp2, temp3;
	scanf("%d%lld", &n, &m);
	for(int i = 0 ; i < n ; i++)
		scanf("%lld", &p[i]);
	fact[0] = (lli)1 % m;
	for(int i = 1 ; i < m ; i++){
		fact[i] = (lli)i * fact[i-1];
		fact[i] %= m;
	}
	ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(p[i] % (lli)2 == 0){
			temp1 = p[i] / (lli)2;
			temp1 %= m;
			temp2 = p[i] % m;
			temp3 = (p[i] + (lli)1) % m;
			temp1 *= temp2;
			temp1 %= m;
			temp1 *= temp3;
			temp1 %= m;
		}
		else{
			temp1 = (p[i] + (lli)1) / (lli)2;
			temp1 %= m;
			temp2 = p[i] % m;
			temp2 *= temp2;
			temp2 %= m;
			temp1 *= temp2;
			temp1 %= m;
		}
		if(p[i]+1 < m){
			temp1 += fact[p[i]+1];
			temp1 %= m;
		}
		temp1 += (m - (lli)1);
		temp1 %= m;
		ans += temp1;
		ans %= m;
	}
	printf("%lld", ans);
	return 0;
}