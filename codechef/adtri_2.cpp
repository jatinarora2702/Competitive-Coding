#include <bits/stdc++.h>
#define N 5000001
using namespace std;
int a[N], ans[N];
int main(){
	int t, n, f;
	for(int i = 0 ; i < N ; i++)
		a[i] = i;
	for(int i = 2 ; i < N ; i++){
		f = 0;
		if(a[i] != -1){
			if(i % 4 == 1){
				f = 1;
				ans[i] = 1;
			}
			for(int j = 2*i ; j < N ; j+=i){
				a[j] = -1;
				ans[j] += f;
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(ans[n] > 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}