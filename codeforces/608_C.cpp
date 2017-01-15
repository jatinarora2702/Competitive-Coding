#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define N 100005
using namespace std;
pair < int, int > p[N];
map < int, int > dp;
vector < int > v;
map < int, int > :: iterator it;
int main() {
	int n, minm, j, k1, k2;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &p[i].FF, &p[i].SS);
	}
	sort(p, p+n);
	for(int i = 0 ; i < n ; i++)
		v.PB(p[i].FF);
	dp[p[0].FF] = 0;
	for(int i = 1 ; i < n ; i++){
		j = lower_bound(v.begin(), v.end(), p[i].FF - p[i].SS) - v.begin();
		j--;
		if(j >= 0)
			dp[p[i].FF] = dp[p[j].FF];
		else
			dp[p[i].FF] = 0;
		j++;
		dp[p[i].FF] += (i-j);
	}
	minm = n;
	k1 = n;
	k2 = 0;
	for(it = dp.begin() ; it != dp.end() ; it++){
		k1--;
		k2 = it->SS;
		minm = min(minm, k2 + k1);
	}
	printf("%d", minm);
	return 0;
}