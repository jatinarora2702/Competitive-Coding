#include <bits/stdc++.h>
using namespace std;

int ispalin(int n) {
	int m, r, n1;
	n1 = n;
	m = 0;
	while(n1 > 0) {
		r = n1 % 10;
		n1 /= 10;
		m = m * 10 + r;
	}
	if(m == n)
		return 1;
	else
		return 0;
}

int main() {
	int i, j, k, f, m;
	f = 0;
	m = 0;
	for(i = 999 ; i >= 100 ; i--) {
		for(j = 999 ; j >= 100 ; j--) {
			k = i * j;
			if(ispalin(k)) {
				m = max(k, m);
				break;
			}
		}
	}
	printf("%d\n", m);
	return 0;
}