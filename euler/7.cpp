#include <bits/stdc++.h>
#define N 10000000
using namespace std;
int a[N];
int main() {
	int n, cnt, i, j;
	scanf("%d", &n);
	cnt = 1;
	if(n == 1)
		printf("2\n");
	else {
		for(i = 3 ; i < N ; i+=2) {
			if(a[i] == 0) {
				cnt++;
				if(cnt == n) {
					printf("%d\n", i);
					break;
				}
				if(i <= sqrt(N)) {
					for(j = i*i ; j < N ; j+=i) {
						a[j] = 1;
					}
				}
			}
		}
	}
	return 0;
}