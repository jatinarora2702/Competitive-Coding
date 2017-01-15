#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
const int INF = 1e9 + 7;

int a, b, k;
lli n, remcnt[N], powremcnt[2][N];

void getremcnt() {
	int m, i;
	lli cnt;
	m = n % k;
	cnt = n / k;
	for(i = 0 ; i <= m ; i++) {
		remcnt[i] = cnt + 1LL;
	}
	for(i = m+1 ; i < k ; i++) {
		remcnt[i] = cnt;
	}
	if(remcnt[0] > 0)
		remcnt[0]--;
}

int modexp(int x, int p, int mod) {
	if(p == 0) {
		return 1 % mod;
	}
	else if(p == 1) {
		return x % mod;
	}
	lli temp;
	temp = (lli)x * (lli)x;
	temp %= mod;
	int ans = modexp((int)temp, p/2, mod);
	if(p % 2 != 0) {
		temp = (lli)ans * (lli)x;
		temp %= mod;
		ans = (int)temp;
	}
	return ans;
}

int getans(int m1, int m2) {
	int i, v1, v2, ans;
	lli temp, sub;
	for(i = 0 ; i < k ; i++) {
		powremcnt[0][i] = 0LL;
		powremcnt[1][i] = 0LL;
	}
	sub = 0LL;
	for(i = 0 ; i < k ; i++) {
		v1 = modexp(i, m1, k);
		v2 = modexp(i, m2, k);
		if(v1 == 0 && v2 == 0) {
			sub += remcnt[i];
		}
		if(v1 + v2 == k) {
			sub += remcnt[i];
		}
		powremcnt[0][v1] += remcnt[i];
		powremcnt[1][v2] += remcnt[i];
	}
	sub %= INF;
	ans = 0;
	for(i = 1 ; i < k ; i++) {
		assert(powremcnt[0][i] >= 0LL);
		assert(powremcnt[1][k-i] >= 0LL);
		powremcnt[0][i] %= INF;
		powremcnt[1][k-i] %= INF;
		temp = (lli)ans + (lli)powremcnt[0][i] * (lli)powremcnt[1][k-i];
		temp %= INF;
		ans = (int)temp;
		assert(ans >= 0);
	}
	powremcnt[0][0] %= INF;
	powremcnt[1][0] %= INF;
	assert(powremcnt[0][0] >= 0LL);
	assert(powremcnt[1][0] >= 0LL);
	temp = (lli)ans + (lli)powremcnt[0][0] * (lli)powremcnt[1][0];
	temp %= INF;
	cerr << temp << endl;
	temp += (INF - sub);
	temp %= INF;
	ans = (int)temp;
	return ans;
}

int main() {
	int t, h, ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		cin >> a >> b >> n >> k;
		getremcnt();
		ans = getans(a, b);
		cout << "Case #" << h << ": " << ans << endl;
	}
	return 0;
}