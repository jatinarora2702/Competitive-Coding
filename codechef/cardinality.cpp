#include <bits/stdc++.h>
#define N 105
using namespace std;
int v[N][10], a[N];
lli dp[N];
int main(){
	int n, f, rem, temp;
	lli val;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		for(int i = 0 ; i < n ; i++){
			temp = a[i];
			while(temp != 0){
				rem = temp % 10;
				temp /= 10;
				v[i][rem] = 1;
			}
		}
		dp[0] = a[i];
		for(int i = 1 ; i < n ; i++){
			dp[i] = a[i];
			val = 0;
			for(int j = 0 ; j < i ; j++){
				f = 1;
				for(int k = 0 ; k < 10 ; k++){
					if(v[i][k] == 1 && v[j][k] == 1){
						f = 0;
						break;
					}
				}
				if(f == 1){
					val = max(val, dp[j]);
				}
			}
			dp[i] += val;
		}
		val = 0;
		for(int i = 0 ; i < n ; i++){
			val = max(val, dp[i]);
		}
		printf("%lld\n", val);
	}
	return 0;
}