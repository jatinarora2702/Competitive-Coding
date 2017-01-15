#include <bits/stdc++.h>
using namespace std;
int main() {
	int l, p, q;
	double d;
	scanf("%d%d%d", &l, &p, &q);
	d = (double)l / (double)(p+q);
	d = d * (double)p;
	cout << d << "\n";
	return 0;
}