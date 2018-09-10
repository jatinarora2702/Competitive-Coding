#include <bits/stdc++.h>
using namespace std;

#define N 105

int a[N];
int main() {
	int n, p, cnt, i;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	p = 0;
	cnt = 0;
	for(i = 0 ; i < n ; i++) {
		if((p == a[i] && p != 3) || a[i] == 0) {
			cnt++;
			p = 0;
			continue;
		}
		if(a[i] == 3) {
			if(p == 1)
				p = 2;
			else if(p == 2)
				p = 1;
			else
				p = 3;
		}
		else
			p = a[i];
	}
	printf("\n");
	printf("%d\n", cnt);
	return 0;
}