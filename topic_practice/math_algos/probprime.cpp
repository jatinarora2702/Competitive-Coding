#include <bits/stdc++.h>
using namespace std;

int modexp(int num, int mod) {
	int ans, p;
	ans = 1;
	p = mod - 1;
	while(p > 0) {
		if(p % 2 != 0) {
			ans = (ans * num) % mod;
		}
		num = (num * num) % mod;
		p = p >> 1;
	}
	return ans;
}

int isprime(int n, int k) {
	int i, num;
	for(i = 0 ; i < k ; i++) {
		num = (rand() % (n-3)) + 2;
		if(modexp(num, n) != 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n, k;
	srand(time(NULL));
	scanf("%d%d", &n, &k);
	if(isprime(n, k)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}