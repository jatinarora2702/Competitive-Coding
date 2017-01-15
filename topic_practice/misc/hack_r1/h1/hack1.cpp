#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100005
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;
const int MOD = 1e9 + 7;

int a[N];
int main(){
	int t, n, i, cnt, k, dif, prev, j;
	scanf("%d", &t);
	j = 0;
	while(t--){
		j++;
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}
		prev = a[0];
		k = 0;
		cnt = 0;
		for(i = 0 ; i < n ; i++){
			dif = a[i] - prev;
			if(cnt == 0 || (dif <= 10 && dif > 0)){
				cnt++;
				if(cnt == 4){
					cnt = 0;
				}
				else
					prev = a[i];	
			}
			else{
				if(dif <= 0){
					k += (4 - cnt);
					cnt = 0;
				}
				else{
					k++;
					cnt++;
					prev += 10;
					if(cnt == 4){
						cnt = 0;
					}	
				}
				i--;
			}
		}
		if(cnt > 0)
			k += (4 - cnt);
		printf("Case #%d: %d\n", j, k);
	}
	return 0;
}