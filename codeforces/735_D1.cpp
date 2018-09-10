#include <bits/stdc++.h>
#define PB push_back
using namespace std;

const int N = 100005;

vector < int > vp;
int a[N];

void getprimes() {
	int i, j;
	vp.PB(2);
	for(i = 3 ; i < N ; i += 2) {
		if (a[i] == 0) {
			vp.PB(i);
			for(j = 2 * i ; j < N ; j += i)
				a[j] = 1;
		}
	}
}

int isprime(int n) {
	int i, s;
	i = 0;
	s = sqrt(n);
	while(vp[i] <= s) {
		if (n % vp[i] == 0)
			return 0;
		i++;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	getprimes();
	if (n == 2)
		printf("1\n");
	else if (n % 2 == 0)
		printf("2\n");
	else if (isprime(n))
		printf("1\n");
	else if (isprime(n - 2))
		printf("2\n");
	else
		printf("3\n");
	return 0;
}