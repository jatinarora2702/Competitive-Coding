#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int n, k, d, **a, cnt;
	ulli flag, freq;
	scanf("%d%d%d", &n, &k, &d);
	a = new int*[d];
	for(int i = 0 ; i < d ; i++)
		a[i] = new int[n];
	long double maxposs;
	maxposs = pow((long double)k, (long double)d);
	if(maxposs < n)
		printf("-1");
	else{
		freq = 1;
		for(int i = d-1 ; i >= 0 ; i--){
			cnt = 1;
			flag = 0;
			for(int j = 0 ; j < n ; j++){
				a[i][j] = cnt;
				flag++;
				if(flag == freq){
					cnt++;
					flag = 0;
					if(cnt == k+1)
						cnt = 1;
				}
			}
			freq = freq * k;
		}
		for(int i = 0 ; i < d ; i++){
			for(int j = 0 ; j < n ; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}