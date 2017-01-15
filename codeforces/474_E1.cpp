#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 1000005
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
set < lli > sets;
set < lli > :: iterator it;
vector < lli > v;
stack < int > stk;
pii st[4*N];
lli a[N];
int dp[N], s[N];
void update(int ss, int se, int si, pii valp, int pos){
	if(pos >= ss && pos <= se){
		if(ss == se && st[si].FF < valp.FF){
			st[si] = valp;
		}
		else{
			int mid = (ss + se) / 2;
			if(pos <= mid)
				update(ss, mid, 2*si, valp, pos);
			else
				update(mid+1, se, 2*si+1, valp, pos);
			st[si] = (st[2*si].FF >= st[2*si+1].FF) ? st[2*si] : st[2*si+1];
		}
	}
}
pii query(int ss, int se, int qs, int qe, int si){
	if(qs >= ss && qe <= se && qs <= qe){
		if(qs == ss && qe == se)
			return st[si];
		int mid = (ss + se) / 2;
		pii p1 = query(ss, mid, qs, min(qe, mid), 2*si);
		pii p2 = query(mid+1, se, max(mid+1, qs), qe, 2*si+1);
		return (p1.FF >= p2.FF) ? p1 : p2;
	}
	return MP(0, -1);
}
int main(){
	int n, maxm, j, m, pos;
	lli d, x;
	pii p;
	cin >> n >> d;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		sets.insert(a[i]);
	}
	for(it = sets.begin() ; it != sets.end() ; it++){
		v.PB(*it);
	}
	m = v.size();
	for(int i = 0 ; i < 4*N ; i++){
		st[i] = MP(0, -1);
	}
	for(int i = 0 ; i < n ; i++){
		x = a[i] + d;
		j = lower_bound(v.begin(), v.end(), x) - v.begin();
		p = query(0, m-1, j, m-1, 1);
		dp[i] = p.FF;
		s[i] = p.SS;
		x = a[i] - d;
		j = upper_bound(v.begin(), v.end(), x) - v.begin();
		j--;
		p = query(0, m-1, 0, j, 1);
		if(p.FF > dp[i]){
			dp[i] = p.FF;
			s[i] = p.SS;
		}
		dp[i]++;
		j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		p = MP(dp[i], i);
		update(0, m-1, 1, p, j);
	}
	maxm = 0;
	pos = -1;
	for(int i = 0 ; i < n ; i++){
		if(dp[i] > maxm){
			maxm = dp[i];
			pos = i;
		}
	}
	printf("%d\n", maxm);
	while(pos >= 0){
		stk.push(pos+1);
		pos = s[pos];
	}
	while(!stk.empty()){
		pos = stk.top();
		stk.pop();
		printf("%d ", pos);
	}
	printf("\n");
	return 0;
}