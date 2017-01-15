#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, min1, min2, min3, max1, max2, max3, x1, x2, x3, tmp;
	scanf("%d%d%d%d%d%d%d", &n, &min1, &max1, &min2, &max2, &min3, &max3);
	tmp = min2 + min3;
	x1 = n - tmp;
	if(x1 > max1)
		x1 = max1;
	n -= x1;
	tmp = min3;
	x2 = n - tmp;
	if(x2 > max2)
		x2 = max2;
	n -= x2;
	x3 = n;
	printf("%d %d %d", x1, x2, x3);
	return 0;
}