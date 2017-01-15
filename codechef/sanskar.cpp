#include <bits/stdc++.h>
#define N 2100000
using namespace std;
typedef long long int lli;
lli a[N], b[30];
int main(){
	int t, n, k, k1, j, nj, cnt, f;
	lli sum, maxm, val;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		sum = 0;
		maxm = 0;
		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &b[i]);
			sum += b[i];
			maxm = max(maxm, b[i]);
		}
		// if(sum == 0){
		// 	printf("yes\n");
		// 	continue;
		// }
		if(k > n){
			printf("no\n");
			continue;
		}
		if(sum % k != 0){
			printf("no\n");
			continue;
		}
		val = sum / k;
		if(maxm > val){
			printf("no\n");
			continue;
		}
		cnt = 0;
		sort(b, b+n);
		a[0] = b[0];
		nj = 1;
		j = 1;
		if(a[0] == val)
			cnt++;
		for(int i = 1 ; i < n ; i++){
			f = 1;
			a[j++] = b[i];
			if(b[i] == val){
				cnt++;
				f = 0;
			}
			for(int j1 = 0 ; j1 < nj ; j1++){
				sum = a[j1] + b[i];
				if(sum > val+(lli)200000 && maxm <= 100000)
					break;
				a[j++] = sum;
				if(sum == val && f == 1){
					cnt++;
					f = 0;
				}
			}
			nj = j;
		}
		if(cnt < k)
			printf("no\n");
		else 
			printf("yes\n");
	}
	return 0;
}