#include <bits/stdc++.h>
#define N 2000005
using namespace std;
typedef long long int lli;
int a[N];
int main() {
	int i, j, n;
	lli s;
	scanf("%d", &n);
	s = 2LL;
	for(i = 3 ; i < n ; i+=2) {
		if(a[i] == 0) {
			s += (lli)i;
			if(i <= sqrt(n)) {
				for(j = i*i ; j < n ; j+=i)
					a[j] = 1;
			}
		}
	}
	cout << s << "\n";
	return 0;
}