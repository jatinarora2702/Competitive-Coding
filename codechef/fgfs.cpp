#include <bits/stdc++.h>
#define ff first
#define ss second
#define N 100003
using namespace std;
int n, k;
pair < int, pair < int, int > > p[N];
bool cmp(pair < int, pair < int, int > > p1, pair < int, pair < int, int > > p2){
	if(p1.ff != p2.ff)
		return (p1.ff < p2.ff);
	return (p1.ss.ss < p2.ss.ss);
}
int main() {
	int t, x, y, z, i, j, cnt, f;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int it = 0 ; it < n ; it++){
			scanf("%d%d%d", &x, &y, &z);
			p[it] = make_pair(z, make_pair(x, y));
		}
		sort(p, p+n, cmp);
		// for(int it = 0 ; it < n ; it++){
		// 	printf("{%d, (%d, %d)} ", p[it].ff, p[it].ss.ff, p[it].ss.ss);
		// }
		// printf("\n");
		cnt = 0;
		i = 0;
		while(i < n){
			j = p[i].ff;
			f = 0;
			while(i < n && p[i].ff == j){
				if(f <= p[i].ss.ff){
					f = p[i].ss.ss;
					cnt++;	
				}
				i++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}