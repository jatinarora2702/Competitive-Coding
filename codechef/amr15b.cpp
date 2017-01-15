#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005

int a[N], b[N], c[N], n;
vector < int > vp, v;
vector < pii > vf[N];
set < int > st;

bool fn(int x, int y) {
	return x > y;
}

void getprimes() {
	int i, j;
	vp.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(b[i] == 0) {
			vp.PB(i);
			if(i < sqrt(N)) {
				for(j = i*i ; j < N ; j+=2*i) {
					b[j] = 1;
				}
			}
		}
	}
}

void getfactors(int num) {
	int f, j, i, temp;
	temp = num;
	for(i = 0 ; i < vp.size() ; i++) {
		if(vp[i] > sqrt(temp)) {
			break;
		}
		j = 0;
		f = vp[i];
		while(temp % f == 0) {
			f *= vp[i];
			j++;
		}
		f /= vp[i];
		temp /= f;
		if(j > 0) {
			vf[num].PB(MP(vp[i], j));
		}
	}
	if(temp > 1) {
		vf[num].PB(MP(temp, 1));
	}
}

int fastexp(int num, int exp) {
	int ans;
	lli temp;
	if(exp <= 0) {
		return 1;
	}
	if(exp == 1) {
		return num;
	}
	if(exp % 2 == 1) {
		ans = num;
	}
	else {
		ans = 1;
	}
	temp = (lli)num * (lli)num;
	temp %= INF;
	num = (int)temp;
	temp = (lli)fastexp(num, exp/2) * (lli)ans;
	temp %= INF;
	ans = (int)temp;
	return ans;
}

int getprodgcd(int pr) {
	int i, j, s;
	lli temp;
	for(i = 0 ; i < n ; i++) {
		j = lower_bound(vf[a[i]].begin(), vf[a[i]].end(), MP(pr, 0)) - vf[a[i]].begin();
		if(j < vf[a[i]].size() && vf[a[i]][j].FF == pr) {
			c[i] = vf[a[i]][j].SS;
		}
		else {
			c[i] = 0;
		}
	}
	sort(c, c+n, fn);
	s = 0;
	for(i = 0 ; i < n ; i++) {
		temp = (lli)fastexp(2, i);
		temp *= c[i];
		temp %= INF;
		temp += s;
		temp %= INF;
		s = (int)temp;
	}
	s %= (INF-1);
	s = fastexp(pr, s);
	return s;
}

void getreqprimes() {
	int i, j;
	st.clear();
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < vf[a[i]].size() ; j++) {
			st.insert(vf[a[i]][j].FF);
		}
	}
	v.clear();
	for(auto it : st) {
		v.PB(it);
	}
}

int main() {
	int t, i, ans, j;
	lli temp;
	getprimes();
	for(i = 2 ; i < N ; i++) {
		getfactors(i);
	}
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		ans = 1;
		getreqprimes();
		for(i = 0 ; i < v.size() ; i++) {
			temp = (lli)getprodgcd(v[i]);
			temp *= ans;
			temp %= INF;
			ans = (int)temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}