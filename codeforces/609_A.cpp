#include <bits/stdc++.h>
#define N 105
using namespace std;
int a[N];
bool fn(int a, int b){
	return a > b;
}
int main(){
	int n, m, j;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	sort(a, a+n, fn);
	j = 0;
	while(m > 0){
		m -= a[j];
		j++;
	}
	printf("%d", j);
	return 0;
}