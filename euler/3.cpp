#include <bits/stdc++.h>
#define N 10000000
using namespace std;

typedef long long int lli;

int isprime(lli n) {
	int i;
	if(n % 2 == 0)
		return 0;
	for(i = 3 ; i <= sqrt(n) ; i+=2) {
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int main() {
	int i, f;
	lli n, k, maxm;
	cin >> n;
	maxm = 1;
	f = 0;
	if(n % (lli)2 == 0LL) {
		k = n / (lli)2;
		if(isprime(k)) {
			maxm = k;
			f = 1;
		}
		else
			maxm = 2;
	}
	if(f == 0) {
		for(i = 1 ; i <= sqrt(n) ; i+=2) {
			if(n % (lli)i == 0LL) {
				k = n / (lli)i;
				if(isprime(k)) {
					maxm = k;
					break;
				}
				if(isprime(i)) {
					maxm = max(maxm, (lli)i);
				}
			}
		}
	}
	cout << maxm << "\n";
	return 0;
}