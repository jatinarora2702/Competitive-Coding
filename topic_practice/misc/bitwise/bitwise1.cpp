#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long  f[3],n;
		cin >> f[0] >> f[1] >> n;
		f[2] = f[1]^f[0];
		n %= 3LL;
		cout << f[n];
	}
	return 0;
}
