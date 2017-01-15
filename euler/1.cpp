#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main() {
	int n, k, m;
	lli s1, s2, s3;
	scanf("%d", &n);
	n--;
	k = n / 3;
	m = 3 * k;
	s1 = ((lli)k * ((lli)3 + (lli)m)) / (lli)2;
	k = n / 5;
	m = 5 * k;
	s2 = ((lli)k * ((lli)5 + (lli)m)) / (lli)2;
	k = n / 15;
	m = 15 * k;
	s3 = ((lli)k * ((lli)15 + (lli)m)) / (lli)2;
	cout << s1 + s2 - s3 << endl;
	return 0;
}