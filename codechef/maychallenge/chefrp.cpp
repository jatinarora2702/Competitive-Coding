#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, n, *a, min, sum;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		a = new int[n];
		for(int i = 0 ; i < n ; i++ ) {
			scanf("%d", &a[i]);
		}
		min = a[0];
		sum = a[0];
		for(int i = 1 ; i < n ; i++ ) {
			sum = sum + a[i];
			if(a[i] < min)
				min = a[i];
		}
		if(min < 2)
			printf("-1\n");
		else
			printf("%d\n", sum - min + 2);
	}
	return 0;
}