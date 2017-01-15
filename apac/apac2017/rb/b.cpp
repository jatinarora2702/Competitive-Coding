#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int add(int a , int b, int mod){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b, int mod){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int power(int a , int b, int mod){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a, mod);
        }
        a = mult(a , a, mod);
        b >>= 1;
    }
    return res;
}

int rema[N], remb[N];
int rcounta[N], rcountb[N];

int main() {
	int t, a, b, k, h, m, m1, i;
	lli n, s, temp;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		cin >> a >> b >> n >> k;
		for(i = 0 ; i < k ; i++) {
			rcounta[i] = 0;
			rcountb[i] = 0;
		}
		for(i = 1 ; i <= n ; i++) {
			m = power(i, a, k);
			rema[i] = m;
			rcounta[m]++;
			m = power(i, b, k);
			remb[i] = m;
			rcountb[m]++;
		}
		s = 0LL;
		for(i = 1 ; i <= n ; i++) {
			m = rema[i];
			m1 = k-m;
			m1 %= k;
			temp = rcountb[m1];
			if(remb[i] == m1) {
				temp--;
			}
			s += temp;
			s %= INF;
		}
		cout << "Case #" << h << ": " << s << endl;
	}
	return 0;
}