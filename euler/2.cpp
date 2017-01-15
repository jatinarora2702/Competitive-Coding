#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int a, b, c, n;
	lli s;
	a = 1;
	b = 1;
	s = 0LL;
	scanf("%d", &n);
	while(1) {
		c = a + b;
		if(c % 2 == 0)
			s += (lli)c;
		if(c > n)
			break;
		a = b;
		b = c;
	}
	cout << s << "\n";
	return 0;
}