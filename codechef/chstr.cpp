#include <bits/stdc++.h>
#define N 5005
#define MOD (10e9+7)
using namespace std;
typedef long long int lli;
int a[N];
int getindex(int k, int n){
	int b, e, m;
	b = 0;
	e = n-1;
	while(b <= e){
		m = (b + e) / 2;
		if(a[m] >= k)
			b = m+1;
		else if(a[m] < k)
			e = m-1;
	}
	if(b == m)
		return -1;
	else
		return e;
}
int main(){
	int t, n, q, ans;
	lli sum;
	scanf("%d", &t);
	for(int i = 1 ; i < N ; i++)
		a[i] = N-i+1;
	while(t--){
		scanf("%d%d", &n, &q);
		for(int i = 0 ; i < q ; i++){
			scanf("%d", &k);
			if(k > a[1])
				printf("0\n");
			else{
				j = getindex(k, n);
				sum = 0;
				ans = 0;
				for(l = j ; l >= 0 ; l--){
					
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}