#include <bits/stdc++.h>
#define N 300005
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int MOD = 998244353;

map < int, int > mp1, mp2;
map < pii, int > mp3;
vector < pii > v;

int add(int x, int y) {
	lli tmp = x;
	tmp += y;
	tmp %= MOD;
	return (int)tmp;
}

int sub(int x, int y) {
	lli tmp = x;
	tmp -= y;
	tmp += MOD;
	tmp %= MOD;
	return (int)tmp;
}

int mul(int x, int y) {
	lli tmp = x;
	tmp *= y;
	tmp %= MOD;
	return (int)tmp;
}

int fact(int x) {
	int p = 1;
	for(int i = 2; i <= x; i++) {
		p = mul(p, i);
	}
	return p;
}

int pow(int x, int y) {
	if (y == 0) {
		return 1 % MOD;
	}
	int p = pow(x, y/2);
	int t = mul(p, p);
	if (y % 2 == 1) {
		t = mul(t, x);
	}
	return t;
}

int division(int x, int y) {
	return mul(x, pow(y, MOD-2));
}

int main() {
	int n, p1, p2, p3, f, ans, x, y;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		pii p = MP(x, y);
		if (mp1.find(x) != mp1.end()) {
			mp1[x]++;
		}
		else {
			mp1[x] = 1;
		}
		if (mp2.find(y) != mp2.end()) {
			mp2[y]++;
		}
		else {
			mp2[y] = 1;
		}
		if (mp3.find(p) != mp3.end()) {
			mp3[p]++;
		}
		else {
			mp3[p] = 1;
		}
	}
	p1 = 1;
	p2 = 1;
	p3 = 1;
	for(auto& it : mp1) {
		p1 = mul(p1, fact(it.SS));
	}
	for(auto& it : mp2) {
		p2 = mul(p2, fact(it.SS));
	}
	for(auto& it : mp3) {
		p3 = mul(p3, fact(it.SS));
		v.PB(it.FF);
	}
	sort(v.begin(), v.end());
	f = 1;
	for(int i = 1; i < v.size(); i++) {
		if (v[i].SS < v[i-1].SS) {
			f = 0;
			break;
		}
	}
	// cout << f << " " << fact(n) << " " << p1 << " " << p2 << " " << p3 << "\n";
	ans = sub(fact(n), p1);
	ans = sub(ans, p2);
	ans = add(ans, f * p3);
	cout << ans << "\n";
	return 0;
}