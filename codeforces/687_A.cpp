#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100000005

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int a[N];
vector < int > v, v1;
int main() {
	int i;
	v.PB(2);
	for(i = 3 ; i < N ; i += 2) {
		if(a[i] == 0) {
			v.PB(i);
			if(i <= sqrt(N)) {
				for(j = i*i ; j < N ; j += i)
					a[j] = 1;
			}
		}
	}
	for(i = 0 ; i < v.size() ; i++) {
		if(v[i] > k)
			break;
		f = 1;
		while(k % f == 0) {
			f *= v[i];
		}
		if(f > 1) {
			v1.PB(f);
		}
	}
	for(i = 0 ; i < v1.size() ; i++) {
		for(auto it : mp) {
			mp[it.FF * v1[i]] = 1;
		}
		mp[v[i]] = 1;
	}
	for(i = 0 ; i < )
}