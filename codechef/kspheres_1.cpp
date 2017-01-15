#include <iostream>
#include <cstdio>
#define N 1005
#define MOD 1000000007
using namespace std;
typedef long long int lli;
int ucnt[N], lcnt[N];
lli sph[N], ans[N], p;
int main() {
	int n, m, c, x;
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		ucnt[x]++;
	}
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &x);
		lcnt[x]++;
	}
	for(int i = 1 ; i <= c ; i++){
		sph[i] = (lli)ucnt[i] * (lli)lcnt[i];
		sph[i] %= (lli)(MOD);
	}
	for(int i = 1 ; i <= c ; i++){
		p = 1;
		for(int j = i ; j <= c ; j++){
			p *= sph[j];
			p %= (lli)(MOD);
			ans[i+j-1] += p;
			ans[i+j-1] %= (lli)(MOD);
		}
	}
	for(int i = 2 ; i <= (c+1) ; i++)
		printf("%lld ", ans[i]);
	return 0;
}