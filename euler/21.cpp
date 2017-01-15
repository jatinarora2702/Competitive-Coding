#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define N 10005
using namespace std;
typedef long long int lli;
lli b[N];
vector < int > p;
set < pair < int, int > > st;
int a[N], c[N];
int main() {
	int i, j, k, n, sf, f;
	lli s;
	scanf("%d", &n);
	p.PB(2);
	for(i = 3 ; i < n ; i+=2) {
		if(a[i] == 0) {
			p.PB(i);
			if(i <= sqrt(n)) {
				for(j = i*i ; j < n ; j+=i)
					a[j] = 1;
			}
		}
	}
	for(i = 2 ; i < n ; i++) {
		s = 1LL;
		for(j = 0 ; j < p.size() ; j++) {
			if(p[j] > i)
				break;
			k = 0;
			f = 1;
			sf = 0;
			while(i % f == 0) {
				sf += f;
				f *= p[j];
				k++;
			}
			k--;
			// printf("%d[%d](%d)\n", i, p[j], sf);
			s *= (lli)sf;
		}
		b[i] = s-i;
		// printf("%d -> %lld\n", i, b[i]);
	}
	k = 0;
	for(i = 2 ; i < n ; i++) {
		if(b[i] < n && b[i] > 1 && b[i] != i && b[b[i]] == i){
			if(st.find(MP(i, b[i])) == st.end() && st.find(MP(b[i], i)) == st.end()) {
				st.insert(MP(i, b[i]));
				// printf("(%d, %lld)\n", i, b[i]);
				k += (b[i] + i); 
			}
		}
	}
	printf("%d\n", k);
	return 0;
}