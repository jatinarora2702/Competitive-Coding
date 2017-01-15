#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, m, *a, x, y, it, cnt;
	scanf("%d%d", &n, &k);
	a = new int[n];
	for(int i = 0 ; i < k ; i++){
		scanf("%d%d", &m, &x);
		x--;
		for(int j = 1 ; j < m ; j++){
			scanf("%d", &y);
			y--;
			a[x] = y;
			x = y;
		}
		a[x] = -1;
	}
	for(it = 0 ; it < n ; it++){
		if(a[it] != (it+1))
			break;
	}
	cnt = 0;
	for(int i = it ; i < n ; i++){
		if(a[i] != -1)
			cnt++;
	}
	cnt += (n-it-1);
	printf("%d", cnt);
	return 0;
}