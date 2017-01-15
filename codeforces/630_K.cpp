#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define N 1000
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;

int main(){
	lli x2, x3, x5, x6, x7, x10, x14, x15, x21, x35, x30, x42, x70, x105, x210;
	lli n;
	cin >> n;
	x2 = n / (lli)2;
	x3 = n / (lli)3;
	x5 = n / (lli)5;
	x6 = n / (lli)6;
	x7 = n / (lli)7;
	x10 = n / (lli)10;
	x14 = n / (lli)14;
	x15 = n / (lli)15;
	x21 = n / (lli)21;
	x35 = n / (lli)35;
	x30 = n / (lli)30;
	x42 = n / (lli)42;
	x70 = n / (lli)70;
	x105 = n / (lli)105;
	x210 = n / (lli)210;

	lli ans;

	ans = x2 + x3 - x6 + x5 - x10 - x15 + x7 - x14 - x21 - x35 + x30 + x42 + x70 + x105 - x210;
	ans = n - ans;
	cout << ans << endl;
	return 0;
}