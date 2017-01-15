#include <bits/stdc++.h>

#define FORI(i, a, b) for(int (i) = (a) ; (i) < (b) ; (i)++)
#define FORD(i, a, b) for(int (i) = (a) ; (i) > (b) ; (i)--)
#define FF first
#define SS second
#define SC1(a) scanf("%d", &(a))
#define SC2(a, b) scanf("%d%d", &(a), &(b))
#define SC3(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define PB push_back
#define MP make_pair
#define MOD 1000000009
#define PII pair < int, int >
#define VI vector < int > 
#define VPII vector < pair < int, int > > 
#define VVI vector < vector < int > >
#define ITV vector < int > :: iterator
#define all(v) v.begin(), v.end() 

#define N 103

using namespace std;
typedef long long int lli;

char a[N], c[N];
int next[N], cnt[N];
int b, d, p, ans, n, m;

int main(){
	SC2(b, d);
	scanf("%s%s", a, c);
	n = strlen(a);
	m = strlen(c);
	FORI(i, 0, m){
		p = i;
		FORI(j, 0, n){
			if(c[p] == a[j]){
				p++;
				// printf("pp\n");
				if(p == m){
					p = 0;
					cnt[i]++;
				}
			}
		}
		next[i] = p;
	}
	p = 0;
	// FORI(i, 0, m)
	// 	printf("%d ", cnt[i]);
	FORI(i, 0, b){
		ans += cnt[p];
		p = next[p];
	}
	// cout << ans << endl;
	ans /= d;
	printf("%d", ans);
	return 0;
}