#include <bits/stdc++.h>
#define N 100005
using namespace std;
int l[N], r[N], q[N], a[N], sum[N], st[4*N];
void build(int ss, int se, int si){
	if(ss == se)
		st[si] = a[se];
	else{
		int mid = (ss + se) / 2;
		build(ss, mid, 2*si);
		build(mid+1, se, 2*si+1);
		st[si] = st[2*si] & st[2*si+1];
	}
}
int query(int ss, int se, int qs, int qe, int si){
	if(qs == ss && qe == se)
		return st[si];
	int mid = (ss + se) / 2;
	int ans = (1 << 30) - 1;
	if(qs <= mid)
		ans &= query(ss, mid, qs, min(qe, mid), 2*si);
	if(qe > mid)
		ans &= query(mid+1, se, max(qs, mid+1), qe, 2*si+1);
	return ans;
}
int main(){
	int n, m, f;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		l[i]--;
	}
	for(int i = 0 ; i < 31 ; i++){
		for(int j = 0 ; j < n ; j++)
			sum[j] = 0;
		for(int j = 0 ; j < m ; j++){
			if((q[j] >> i) & 1){
				sum[l[j]]++;
				sum[r[j]]--;	
			}
		}
		if(sum[0] > 0)
			a[0] |= (1 << i);
		for(int j = 1 ; j < n ; j++){
			sum[j] += sum[j-1];
			if(sum[j] > 0)
				a[j] |= (1 << i);
		}
	}
	build(0, n, 1);
	f = 1;
	for(int i = 0 ; i < m ; i++){
		if(query(0, n, l[i], r[i]-1, 1) != q[i]){
			f = 0;
			break;
		}
	}
	if(f == 0)
		printf("NO");
	else{
		printf("YES\n");
		for(int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
	}
	return 0;
}