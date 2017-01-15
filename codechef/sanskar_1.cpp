#include <bits/stdc++.h>
#define N 25
using namespace std;
typedef long long int lli;
int used[N];
lli a[N];
int n, k;
int has_subsets(lli curr, int i, lli sum, int cnt){
	if(i < n){
		if(used[i] == 0){
			if(curr + a[i] == sum){
				used[i] = 1;
				if(cnt + 1 == k)
					return 1;
				return has_subsets(0, 0, sum, cnt+1);
				}
			else if(curr + a[i] < sum){
				used[i] = 1;
				int x = has_subsets(curr + a[i], i+1, sum, cnt);
				if(x)
					return 1;
				else{
					used[i] = 0;
					return has_subsets(curr, i+1, sum, cnt);
				}
			}
			else
				return has_subsets(curr, i+1, sum, cnt);	
		}
		else
			return has_subsets(curr, i+1, sum, cnt);
	}
	return 0;
}
int main(){
	int t;
	lli sum;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		sum = 0;
		for(int i = 0 ; i < n ; i++)
			used[i] = 0;
		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		if(sum % k != 0)
			printf("no\n");
		else if(has_subsets(0, 0, sum/k, 0))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}