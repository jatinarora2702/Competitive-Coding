#include <bits/stdc++.h>
#define PB push_back
#define N 200005
using namespace std;
typedef long long int lli;
const int INF = 1e9 + 7;
int a[N], v[N], b1[N], n, ans, c;
lli temp;

int power(int a, int b, int mod) {
	lli temp1;
	int ans;
	if(b == 0)
		return 1;
	ans = 1;
	if(b & 1)
		ans = a;
	b >>= 1;
	temp1 =  power(a, b, mod);
	temp1 *= temp1;
	temp1 %= mod;
	temp1 *= ans;
	temp1 %= mod;
	ans = temp1;
	return ans;
}

void dfs_visit(int s, int k, int p) {
	v[s] = k;
	b1[s] = p;
	// printf("s=%d | k=%d\n", s, k);
	if(v[a[s]] != -1) {
		// printf("doinf: %d\n", k - v[a[s]] + 1);
		if(b1[a[s]] == p && (k - v[a[s]] + 1) > 1) {
			temp = power(2, k - v[a[s]] + 1, INF);
			temp += INF - 2;
			temp %= INF;
			temp *= ans;
			temp %= INF;
			ans = temp;
			c += k - v[a[s]] + 1;
		}
		return;
	}
	dfs_visit(a[s], k+1, p);
}

void dfs() {
	int i, p;
	for(i= 0  ; i < n ; i++) {
		v[i] = -1;
	}
	p = 1;
	for(i = 0 ; i < n ; i++) {
		if(v[i] == -1) {
			dfs_visit(i, 0, p++);
		}
	}
}

int main() {
	int i;
	lli temp1;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	c = 0;
	ans = 1;
	dfs();
	c = n - c;
	temp1 = power(2, c, INF);
	temp1 *= ans;
	temp1 %= INF;
	ans = temp1;
	printf("%d\n", ans);
	return 0;
}