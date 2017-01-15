#include <bits/stdc++.h>
using namespace std;

void exteuclid(int a, int b, int &x, int &y) {
	int x1, y1, temp;
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	exteuclid(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b) * y1;
}

int invmod(int a, int m) {
	int inva, temp;
	exteuclid(a, m, inva, temp);
	return inva;
}

int main() {
	int n, m, inv;
	scanf("%d%d", &n, &m);
	inv = invmod(n, m);
	cout << inv << endl;
	return 0;
}