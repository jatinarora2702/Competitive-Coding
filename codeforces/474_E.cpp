#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
lli h[N], hcomp[N], hsort[N];
int n, d, prev[N], dp[N], printer[N];
map < lli, lli > mp;
typedef struct{
	lli ht;
	int index;
	lli orig_ht;
	int dp_val; 
}seg;
seg st[N], smax1, smax2;
lli *ptr1, *ptr2, maxht;
void build(int ss, int se, int si){
	if(ss > se)
		return;
	if(ss == se){
		st[si].ht = hcomp[ss];
		st[si].orig_ht = h[ss];
		st[si].index = ss;
		st[si].dp_val = -1;
		return;
	}
	int mid = (ss + se) / 2;
	build(ss, mid, 2*si);
	build(mid+1, se, 2*si+1);
	st[si].ht = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].ht : st[2*si+1].ht;
	st[si].index = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].index : st[2*si+1].index;
	st[si].orig_ht = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].orig_ht : st[2*si+1].orig_ht;
	st[si].dp_val = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].dp_val : st[2*si+1].dp_val;
}
void update(int ss, int se, int si, int dp_value, lli ht_comp, int index_){
	if(ht_comp < ss || ht_comp > se || ss > se)
		return;
	if(ss == se){
		st[si].dp_val = dp_value;
		st[si].index = index_;
		// cout << "in : " << si << " " << ss << endl;
		return;
	}
	int mid = (ss + se) / 2;
	update(ss, mid, 2*si, dp_value, ht_comp, index_);
	update(mid+1, se, 2*si+1, dp_value, ht_comp, index_);
	st[si].ht = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].ht : st[2*si+1].ht;
	st[si].index = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].index : st[2*si+1].index;
	st[si].orig_ht = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].orig_ht : st[2*si+1].orig_ht;
	st[si].dp_val = (st[2*si].dp_val > st[2*si+1].dp_val) ? st[2*si].dp_val : st[2*si+1].dp_val;
}
seg query(int ss, int se, int qs, int qe, int si){
	// 	cout << ss << " " << se << " " << qs << " " << qe << " " << si << endl;
	if(qs <= ss && qe >= se)
		return st[si];
	if(qe < ss || qs > se || ss > se){
		seg dummy;
		dummy.ht = dummy.orig_ht = (lli)-1;
		dummy.index = -1;
		dummy.dp_val = -1;
		return dummy;
	}
	int mid = (ss + se) / 2;
	seg s1, s2;
	s1 = query(ss, mid, qs, qe, 2*si);
	s2 = query(mid+1, se, qs, qe, 2*si+1);
	return (s1.dp_val > s2.dp_val) ? s1 : s2;
}
int compress(){
	for(int i = 0 ; i < n ; i++)
		hsort[i] = h[i];
	sort(hsort, hsort+n);
	int t = 0;
	for(int i = 0 ; i < n ; i++)
		mp[hsort[i]] = t++;
	for(int i = 0 ; i < n ; i++)
		hcomp[i] = mp[h[i]];
	return t;
}
int main() {
	int _qs, _qe, k1, k2, maxm, j;
	scanf("%d%d", &n, &d);
	for(int i = 0 ; i < n ; i++)
		cin >> h[i];
	// for(int i = 0 ; i < N ; i++){
	// 	st[i].ht = -1;
	// 	st[i].orig_ht = -1;
	// 	st[i].dp_val = -1;
	// 	st[i].index = -1;
	// }
	maxht = compress();		
	dp[0] = 1;
	prev[0] = -1;
	// printf("qq :");
	// for(int i =0  ; i < n ; i++)
	// 	printf("%lld ", hcomp[i]);
	// printf("\n");
	// // cout << maxht << endl;
	build(0, maxht, 1);
	// cout << "start\n";
	update(0, maxht, 1, 1, hcomp[0], 0);
	// cout << "end\n";
	for(int i = 1 ; i < n ; i++){
		k1 = h[i] - d;
		k2 = h[i] + d;
		// cout << "k2=" << k2 << endl;
		// cout << k1 << " ";
		ptr1 = upper_bound(hsort, hsort+n, k1);
		k1 = ptr1 - hsort;
		k1--;
		// cout << "kk1=" << k1 << endl;
		// cout << hsort[k1] << " ";
		if(k1 >= 0){
		k1 = mp[hsort[k1]];
		// cout << k1 << endl;
		smax1 = query(0, maxht, 0, k1, 1);
			
		}
		else 
			smax1.dp_val = -1;
		ptr2 = upper_bound(hsort, hsort+n, k2);
		// cout << k2 << " ";
		k2 = ptr2 - hsort;
		k2--;
		// cout << k2 << endl;
		if(k2 >= 0){
		// cout << hsort[k2] << " ";
		k2 = mp[hsort[k2]];
		// cout << k2 << endl;
		smax2 = query(0, maxht, k2, maxht, 1);
			
		}else
			smax2.dp_val = -1;
		
		// cout << "ppppppppp\n";
		// cout << "yyyyyyyy\n";
		// cout << "wwwwwwwwwww\n";
		// cout << "i: " << smax1.index << " " << smax2.index << endl;
		// cout << "ii " << smax1.dp_val << " " << smax2.dp_val << endl;
		// cout << "io " << smax1.orig_ht << " " << smax2.orig_ht << endl;
		if(smax1.dp_val <= 0 && smax2.dp_val <= 0){
			dp[i] = 1;
			prev[i] = -1;
		}
		else if(smax1.dp_val <= 0){
			dp[i] = smax2.dp_val + 1;
			prev[i] = smax2.index;
		}
		else if(smax2.dp_val <= 0){
			dp[i] = smax1.dp_val + 1;
			prev[i] = smax1.index;
		}
		else{
			if(smax1.dp_val >= smax2.dp_val){
				dp[i] = smax1.dp_val + 1;
				prev[i] = smax1.index;
			}
			else{
				dp[i] = smax2.dp_val + 1;
				prev[i] = smax2.index;
			}
		}
		// if(smax1.dp_val > 0 && dp[i] < smax1.dp_val + 1){
		// 	dp[i] = smax1.dp_val + 1;
		// 	prev[i] = smax1.index;
		// 	printf("rr\n");
		// }
		// else if(smax2.dp_val > 0 && dp[i] < smax2.dp_val + 1){
		// 	dp[i] = smax2.dp_val + 1;
		// 	prev[i] = smax2.index;
		// 	printf("qq\n");
		// }
		// cout << "llllllllll\n";
		// cout << dp[i] << endl;
		update(0, maxht, 1, dp[i], hcomp[i], i);
		// cout << "eeeeeeeeeeeeeeeee\n";
	}
	maxm = 0;
	// cout << "kkkkkkkkkkkkkk\n";
	// for(int i = 0 ; i < n ; i++)
	// 	printf("%d ", dp[i]);
	// printf("\n");
	for(int i = 1 ; i < n ; i++)
		if(maxm < dp[i])
			maxm = i;
	printf("%d\n", dp[maxm]);
	j = maxm;
	cout << maxm << endl;
	// cout << "prev: ";
	// for(int i = 0 ; i < n;  i++)
	// 	printf("%d ", prev[i]);
	// printf("\n");
	int pindex = 0;
	while(j > -1){
		printer[pindex++] = j+1;
		// printf("%d ", j+1);
		j = prev[j];
	}
	for(int i = pindex-1 ; i >= 0 ; i--)
		printf("%d ", printer[i]);
	return 0;
}