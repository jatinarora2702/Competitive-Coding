#include <bits/stdc++.h>
#define ff first
#define ss second
#define N 100005
#define D 205
#define INF 1000000000
using namespace std;
int l[N], d[N], cnt[D], remmorecost[N], seen[N], lencost[N], lencnt[N], cost[N];
pair < int, int > q[N];
bool cmp1(pair < int, int > p1, pair < int, int > p2){
	return (p1.ff < p2.ff);
}
int main() {
	int n, k, k1, k2, minm;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &l[i]);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	for(int i = 0 ; i < n ; i++)
		q[i] = make_pair(l[i], d[i]);
	sort(q, q+n, cmp1);
	for(int i = 0 ; i < n ; i++){
		lencost[l[i]-1] += d[i];
		lencnt[l[i]-1]++;
	}
	k = 0;
	for(int i = N ; i >= 0 ; i--){
		if(lencnt[i] != 0){
			remmorecost[i] += k;
			k += lencost[i];
		}
	}
	for(int i = 0 ; i < n ; i++){
		if((seen[q[i].ff-1] == 0) && (lencnt[q[i].ff-1] != 0)){
			seen[q[i].ff-1] = 1;
			k = lencnt[q[i].ff-1];
			k1 = (i+k) - (2*k-1);
			cost[q[i].ff-1] += remmorecost[q[i].ff-1];
			for(int j = 0 ; j < D ; j++){
				if(k1 <= 0)
					break;
				k2 = cnt[j];
				if(k2 > k1)
					k2 = k1;
				cost[q[i].ff-1] += (j+1) * k2;
				k1 -= k2;
			}
			cnt[q[i].ss-1]++;
		}
		else if(seen[q[i].ff-1] == 1)
			cnt[q[i].ss-1]++;
	}
	minm = INF;
	for(int i = 0 ; i < n ; i++){
		minm = min(minm, cost[q[i].ff-1]);
	}
	printf("%d", minm);
	return 0;
}