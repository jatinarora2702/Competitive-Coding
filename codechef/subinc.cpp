#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int lli;
int main() {
	int t, n, prev, x, k, r, l;
	lli cnt;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cnt = 0;
		scanf("%d", &x);
		l = r = 0;
		prev = x;
		for(int i = 1 ; i < n ; i++){
			scanf("%d", &x);
			if(x >= prev)
				r++;
			else{
				k = r - l + 1;
				cnt += ((lli)k * (lli)(k+1)) / (lli)2;
				l = r = i;
			}
			prev = x;
		}
		k = r - l + 1;
		cnt += ((lli)k * (lli)(k+1)) / (lli)2;
		printf("%lld\n", cnt);
	}
	return 0;
}