#include <cstdio>
#include <cmath>
#define N 32000
using namespace std;
int mark[N], p[N];
int main(){
	int t, m, n, k, f, sq;
	k = 0;
	for(int i = 2 ; i < N ; i++){
		if(mark[i] == 0){
			mark[i] = 1;
			p[k++] = i;
			for(int j = 2*i ; j < N ; j += i)
				mark[j] = -1;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &n);
		if(m == 1)
			m++;
		for(int i = m ; i <= n ; i++){
			sq = sqrt(i);
			f = 1;
			for(int j = 0 ; p[j] <= sq ; j++){
				if(i % p[j] == 0){
					f = 0;
					break;
				}
			}
			if(f == 1)
				printf("%d\n", i);
		}
		printf("\n");
	}
	return 0;
}