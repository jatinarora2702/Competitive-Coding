#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 1000005
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;
typedef pair < lli, int > pllii;
const int MOD = 1e9 + 7;

int w[N];
priority_queue < pllii, vector < pllii >, greater < pllii > > pqm;
priority_queue < lli, vector < lli >, greater < lli > > pqd;
int main(){
	int t, l, n, m, d, i, j;
	lli k, val, maxm;
	pllii p;
	scanf("%d", &t);
	j = 0;
	while(t--){
		while(!pqd.empty())
			pqd.pop();
		while(!pqm.empty())
			pqm.pop();
		j++;
		scanf("%d%d%d%d", &l, &n, &m, &d);
		for(i = 0 ; i < n ; i++){
			scanf("%d", &w[i]);
			pqm.push(MP((lli)w[i], i));
		}
		for(i = 0 ; i < l ; i++)
			pqd.push((lli)0);
		maxm = 0;
		for(i = 0 ; i < l ; i++){
			p = pqm.top();
			pqm.pop();
			pqm.push(MP((lli)(p.FF + (lli)w[p.SS]), p.SS));
			k = pqd.top();
			pqd.pop();
			val = max(k, p.FF) + (lli)d;
			pqd.push(val);
			maxm = max(maxm, val);
		}
		printf("Case #%d: %lld\n", j, maxm);
	}
	return 0;
}