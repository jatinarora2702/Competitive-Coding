#include <bits/stdc++.h>
#define N 5005
using namespace std;
int a[N];
int prod[1 << 18];
int coffee[20];
int main() {
	int t, n, k, d, m, cnt, maxm, sum, kcnt, adder, f;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &k, &d, &m);
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		maxm = 0;
		for(int i = 0 ; i < (1 << n) ; i++){
			cnt = __builtin_popcount(i);
			if(cnt != k)
				continue;
			for(int j = 0 ; j < n ; j++){
				if(i & (1 << j))
					coffee[j] = 1;
				else
					coffee[j] = 0;
			}
			sum = 0;
			f = 0;
			kcnt = 0;
			for(int j = 0 ; j < n ; j++){
				if(f == 1)
					kcnt++;
				if(f == 1 && kcnt > d){
					f = 0;
					kcnt = 0;
				}
				if(coffee[j]){
					f = 1;
					kcnt = 0;
				}
				else{
					adder = a[j];
					if(f == 1)
						adder *= m;
					sum += adder;
				}
			}
			maxm = max(maxm, sum);
		}
		printf("%d\n", maxm);
	}
	return 0;
}