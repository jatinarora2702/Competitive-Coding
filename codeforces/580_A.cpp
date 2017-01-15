#include <bits/stdc++.h>
using namespace std;
int main() {
	int *a, n, cnt, maxm;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	int prev;
	prev = a[0];
	cnt = 1;
	maxm = 1;
	for(int i = 1 ; i < n ; i++){
		if(a[i] >= prev){
			cnt++;
			prev = a[i];
			if(cnt > maxm)
				maxm = cnt;
		}
		else{
			cnt = 1;
			prev = a[i];
		}
	}
	printf("%d", maxm);
	return 0;
}