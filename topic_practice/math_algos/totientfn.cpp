#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int gettotient(int n) {
	int i, tot;
	tot = n;
	if(n % 2 == 0) {
		while(n % 2 == 0) {
			n /= 2;
		}
		tot -= tot/2;
	}
	for(i = 3 ; i <= sqrt(n) ; i+=2) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}
			tot -= tot/i;
		}
	}
	if(n > 1) {
		tot -= tot/n;
	}
	return tot;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", gettotient(n));
	return 0;
}