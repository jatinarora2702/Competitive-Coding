#include <iostream>
#include <stdio.h>
#include <algorithm>
#define N 1000000007
#define M 100000
using namespace std;
typedef unsigned long long int lli;
void pop_r(int *r, int &rn, int n) {
	lli temp;
	int f = 0;
	for(int i = rn+1 ; i < n ; i++ ) {
		temp = (lli)(r[i-1]) * 2;
		r[i] = temp % N;
		f = 1;
	}
	if(f == 1)
		rn = n-1;
}
int main() {
	int t, n, *s, i, j, *r, rn;
	lli sum, rem, temp;
	r = new int[M];
	r[0] = 1;
	rn = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		s = new int[n];
		for(i = 0 ; i < n ; i++ ) {
			scanf("%d", &s[i]);
		}
		sort(s, s+n);
		pop_r(r,rn,n-1);
		sum = r[0];
		for(i = 1 ; i < n-1 ; i++) {
			sum = sum + r[i];
			//sum = sum % N;
		}
		i = 0;
		j = n-1;
		rem = 0;
		while(i < j) {
			temp = s[j] - s[i];
			temp *= (sum % N);
			sum = sum - r[j-1] - r[i];
			temp = temp % N;
			rem = rem + temp;
			rem = rem % N;
			i++;
			j--;
		}
		printf("%llu\n", rem);
	}
	return 0;
}