#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int n;
	lli s;
	scanf("%d", &n);
	s = ((lli)n * (lli)(n+1) * ((lli)n * (lli)n * (lli)3 - (lli)n - (lli)2)) / (lli)12;
	cout << abs(s) << "\n";
	return 0;
}