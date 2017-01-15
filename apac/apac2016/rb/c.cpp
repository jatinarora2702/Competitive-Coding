#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 40000000
#define M 10000000

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int a[N], dp[M][2];
lli b[M];
vector < int > vp, vpow2;
vector < lli > vf;

void sieve() {
	int i, j;
	vp.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			vp.PB(i);
			if(i < sqrt(N)) {
				for(j = i*i ; j < N ; j+=i) {
					a[j] = 1;
				}
			}
		}
	}
}

int getnump(lli n) {
	int i, cnt, f;
	lli m;
	cnt = 0;
	vf.clear();
	for(i = 0 ; i < vp.size() ; i++) {
		f = 0;
		m = 1LL;
		while(n % m == 0LL) {
			m *= vp[i];
			f++;
		}
		m /= vp[i];
		n /= m;
		if(m > 1) {
			vf.PB(m);
			cnt++;
		}
		if(n == 1) {
			break;
		}
	}
	if(n > 1) {
		vf.PB(n);
		cnt++;
	}
	return cnt;
}

int isprime(int n) {
	int i;
	for(i = 0 ; i < vp.size() ; i++) {
		if(n == vp[i])
			return 1;
		if(n % vp[i] == 0)
			return 0;
		if(vp[i] > n)
			break;
	}
	return 1;
}

int isgn(lli n) {
	int s;
	s = 0;
	while(n > 0) {
		s += (n % 10);
		n /= 10;
	}
	return isprime(s);
}

int getmsb(int n) {
	return (upper_bound(vpow2.begin(), vpow2.end(), n) - vpow2.begin() - 1);
}

int getwin(int n) {
	int m, s, k, i, j, f;
	m = 0;
	for(i = 0 ; i < n ; i++) {
		m += (1 << i);
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	b[0] = 1;
	for(i = 1 ; i <= m ; i++) {
		s = i;
		f = getmsb(s);
		k = s - (1 << f);
		b[s] = b[k] * vf[f];
		dp[s][0] = 1;
		dp[s][1] = 0;
		if(isgn(b[s])) {
			continue;
		}
		for(j = 0 ; j < n ; j++) {
			k = 1 << j;
			if(s & k) {
				dp[s][0] &= dp[s-k][1];
				dp[s][1] |= dp[s-k][0];
			}
		}
	}
	// for(i = 0 ; i <= m ; i++) {
	// 	printf("%d: %lld (%d, %d)\n", i, b[i], dp[i][0], dp[i][1]);
	// }
	return dp[m][0];
}

int main() {
	int t, h, m, k, i;
	lli n;
	sieve();
	for(i = 0 ; i < 27 ; i++) {
		vpow2.PB(1 << i);
	}
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%lld", &n);
		m = getnump(n);
		k = getwin(m);
		printf("Case #%d: ", h);
		if(k == 0) {
			printf("Laurence\n");
		}
		else {
			printf("Seymour\n");
		}
	}
	return 0;
}