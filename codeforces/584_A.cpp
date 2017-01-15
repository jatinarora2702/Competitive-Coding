#include <bits/stdc++.h>
#define N 105
using namespace std;
int a[N], b[N];
int main(){
	int n, i, t, rem, m, k;
	scanf("%d%d", &n, &t);
	m = t;
	i = 0;
	while(m > 0){
		rem = m % 10;
		b[i++] = rem;
		m /= 10;
	}
	if(i > n){
		printf("-1");
		return 0;
	}
	k = 0;
	for(int j = 0 ; j < i ; j++)
		a[k++] = b[i-j-1];
	// printf("%d ", a[k]);
	// printf("\n");
	// printf("%d\n", i);
	// // for(int j = i-1 ; j >= 0 ; j--)
	// 	a[k++] = b[j];
	// printf("rr\n");
	// for(int j = 0 ; j < i ; j++)
	// 	printf("%d", a[j]);
	while(i < n)
		a[i++] = 0;
	for(int j = 0 ; j < n ; j++){
		printf("%d", a[j]);
	}
	return 0;
}