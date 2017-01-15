#include <bits/stdc++.h>
#define N 2005
#define FF first
#define SS second
#define MP make_pair
using namespace std;
typedef long long int lli;
pair < int, int > p[N];
pair < pair <lli, lli>, int > pa[N];
pair < lli, lli > pb[N];
int seen[N];
bool fn(pair < pair < lli, lli >, int > p1, pair < pair <lli, lli>, int > p2){
	if(p1.FF.FF == p2.FF.FF){
		return p1.FF.SS > p2.FF.SS;
	}
	return p1.FF.FF > p2.FF.FF;
}
int main(){
	int n, x ,y, k;
	lli ans, minm1, minm2, d1, d2, r1, r2;
	pair < int, int > p1, p2;
	scanf("%d%d%d%d%d", &n, &p1.FF, &p1.SS, &p2.FF, &p2.SS);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &p[i].FF, &p[i].SS);
	}
	minm1 = minm2 = 0LL;
	k = 0;
	for(int i = 0 ; i < n ; i++){
		x = abs(p1.FF - p[i].FF);
		y = abs(p1.SS - p[i].SS);
		d1 = (lli)x * (lli)x + (lli)y * (lli)y;
		x = abs(p2.FF - p[i].FF);
		y = abs(p2.SS - p[i].SS);
		d2 = (lli)x * (lli)x + (lli)y * (lli)y;
		// pa[k++] = MP(d1, MP(1, i));
		// pa[k++] = MP(d2, MP(2, i));
		pa[i] = MP(MP(abs(d1-d2), min(d1, d2)), i);
		pb[i] = MP(d1, d2);
		// if(minm1 >= d1 || minm2 >= d2)
		// 	continue;
		// // cout << "d1=" << d1 << " d2=" << d2 << endl;
		// if(d1 <= d2){
		// 	minm1 = max(minm1, d1);
		// }
		// else{
		// 	minm2 = max(minm2, d2);
		// }
	}
	sort(pa, pa+n, fn);
	r1 = r2 = 0LL;
	for(int i = 0 ; i < n ; i++){
		k = pa[i].SS;
		d1 = pb[k].FF;
		d2 = pb[k].SS;
		// cout << "minm1=" << minm1 << " minm2 = " << minm2 << " d1=" << d1 << " d2=" << d2 << endl;
		if(minm1 >= d1 || minm2 >= d2)
			continue;
		r1 = max(minm1, d1);
		r2 = max(minm2, d2);
		if(r1 + minm2 <= r2 + minm1){
			minm1 = r1;
		}
		else{
			minm2 = r2;
		}

		// if(pa[i].SS.FF == 1){
		// 	if(minm1 >= pa[i].FF){
		// 		seen[pa[i].SS.SS] = 1;
		// 	}
		// 	else if(seen[pa[i].SS.SS] == 0){
		// 		minm1 = pa[i].FF;
		// 	}
		// }
		// else if(pa[i].SS.FF == 2){
		// 	if(minm2 >= pa[i].FF){
		// 		seen[pa[i].SS.SS] = 1;
		// 	}
		// 	else if(seen[pa[i].SS.SS] == 0){
		// 		minm2 = pa[i].FF;
		// 	}	
		// }
	}
	ans = minm1 + minm2;
	// cout << "minm1 = " << minm1 << " minm2 = " << minm2 << endl;
	// ans = minm1 + minm2;
	cout << ans;
	return 0;
}