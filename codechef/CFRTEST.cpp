#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, n, *d, *a, cnt;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		d = new int[n];
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &d[i]);
		}
		a = new int[101];
		for(int i = 0 ; i < n ; i++){
			a[d[i]]++;
		}
		cnt = 0;
		for(int i = 0 ; i < 101 ; i++){
			if(a[i] != 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}