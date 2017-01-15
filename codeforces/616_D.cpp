#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 500005
using namespace std;
typedef long long int lli;
const int MOD = 1e9+7;
int a[N];
int b[1000005];
int main(){
	int n, k, cnt, ii, jj, mi, mj, maxlen, len;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	cnt = 1;
	ii = 0;
	jj = 0;
	b[a[0]] = 1;
	len = 1;
	maxlen = 1;
	mi = ii;
	mj = jj;
	for(int i = 1 ; i < n ; i++){
		jj++;
		len++;
		b[a[i]]++;
		if(b[a[i]] == 1){
			cnt++;
			if(cnt > k){
				while(cnt > k){
					b[a[ii]]--;
					if(b[a[ii]] == 0){
						cnt--;
					}
					ii++;
					len--;
				}
			}
		}
		if(len > maxlen){
			mi = ii;
			mj = jj;
			maxlen = len;
		}
	}
	printf("%d %d", mi+1, mj+1);
	return 0;
}