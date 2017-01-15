#include <bits/stdc++.h>
#define N 200005
using namespace std;
int a[N], st[4*N], lazy[4*N];
void construct(int ss, int se, int si){
	if(ss == se)
		st[si] = a[ss];
	else{
		mid = (ss + se) / 2;
		construct(ss, mid, 2*si);
		construct(mid+1, se, 2*si+1);
		st[si] = min(st[2*si], st[2*si+1]);
	}
}
int query(int ss, int se, int qs, int qe, int si){
	
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	construct(0, n-1, 1);

}