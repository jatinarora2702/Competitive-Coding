#include <iostream>
#include <cstdio>
#define N 1005
using namespace std;
char ans[N], chef[N];
int w[N];
int main(){
	int t, n, cnt, maxm;
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%s", &n, ans, chef);
		for(int i = 0 ; i <= n ; i++)
			scanf("%d", &w[i]);
		cnt = 0;
		for(int i = 0 ; i < n ; i++)
			if(ans[i] == chef[i])
				cnt++;
		if(cnt == n)
			printf("%d\n", w[n]);
		else{
			maxm = w[0];
			for(int i = 1 ; i <= cnt ; i++)
				maxm = max(maxm, w[i]);
			printf("%d\n", maxm);
		}
	}
	return 0;
}