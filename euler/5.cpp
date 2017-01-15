#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define N 10000000
using namespace std;
typedef long long int lli;
int a[N];
vector < int > p;
map < int, int > mp;
int main() {
	int n, i, j, k, f;
	lli ans;
	p.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			p.PB(i);
			if(i <= sqrt(N)) {
				for(j = i*i ; j < N ; j+=i)
					a[j] = 1;
			}
		}
	}
	for(i = 0 ; i < p.size() ; i++)
		mp[p[i]] = 0;
	scanf("%d", &n);
	for(i = 2 ; i <= n ; i++) {
		for(j = 0 ; j < p.size() ; j++) {
			if(p[j] > i)
				break;
			k = 0;
			f = p[j];
			while(i % f == 0) {
				k++;
				f *= p[j];
			}
			mp[p[j]] = max(mp[p[j]], k);
		}
	}
	ans = 1LL;
	for(auto it : mp) {
		ans *= pow(it.FF, it.SS);
	}
	cout << ans << "\n";
	return 0;
}