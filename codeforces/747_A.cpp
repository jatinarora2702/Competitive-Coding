#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, n, d, x, y;
	scanf("%d", &n);
	d = n-1;
	x = 1;
	y = n;
	for(i = sqrt(n) ; i >= 1 ; i--) {
		if(n % i == 0 && d > abs(i - n/i)) {
			d = abs(i - n/i);
			x = min(i, n/i);
			y = max(i, n/i);
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}