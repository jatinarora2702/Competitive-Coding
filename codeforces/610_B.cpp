#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long int lli;
int a[N], v[N];
int main() {
	int n, minm, maxm, k, f;
	lli cnt;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	minm = a[0];
	for(int i = 1 ; i < n ; i++){
		minm = min(minm, a[i]);
	}
	cnt = (lli)minm * (lli)n;
	// cout << "cnt="  << cnt << endl;
	k = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == minm){
			k++;
		}
		else{
			v[k]++;
		}
	}
	if(k > 0)
		v[0] += v[k];
	maxm = v[0];
	for(int i = 0 ; i < k ; i++)
		maxm = max(maxm, v[i]);
	cnt += (lli)maxm;
	cout << cnt;
	return 0;
}