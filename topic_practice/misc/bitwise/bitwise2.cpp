#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int a[N], b[N];
int main(){
	int n, q, l, r, cnt;
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d", &a[i]);
	cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == 3 || a[i] == 4 || a[i] == 6)
			cnt++;
		b[i] = cnt;
	}
	for(int i = 0 ; i < q ; i++){
		scanf("%d%d", &l, &r);
		cnt = b[r];
		if(l > 1)
			cnt -= b[l-1];
		printf("%d\n", cnt);
	}
	return 0;
}