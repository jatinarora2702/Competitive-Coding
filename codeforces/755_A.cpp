#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 1000005

int a[N];

void getprimes() {
	int i, j;
	a[2] = 1;
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			a[i] = 1;
			if(i < sqrt(N)) {
				for(j = i*i ; j < N ; j+=2*i)
					a[j] = -1;
			}
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	if(n % 2 != 0) {
		printf("3\n");
		return 0;
	}
	getprimes();
	for(i = 1 ; i < 1005 ; i++) {
		if(a[n*i+1] != 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}