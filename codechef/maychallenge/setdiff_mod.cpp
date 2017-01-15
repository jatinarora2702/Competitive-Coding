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
	int t, n, *s, *s1, n1, i, j, *r, rn, *b, m;
	lli sum, rem, temp;
	r = new int[M];
	r[0] = 1;
	rn = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n1);
		s1 = new int[n1];
		s = new int[n1];
		b = new int[n1];
		for(i = 0 ; i < n1 ; i++ ) {
			scanf("%d", &s1[i]);
		}
		sort(s1, s1+n1);
		n = -1;
		for(i = 0 ; i < n1 ; i++ ) {
			n++;
			s[n] = s1[i];
			b[n] = 1;
			while(i < n1-1 and s1[i] == s1[i+1]){
				b[n]++;
				i++;
			}
		}
		n++;
		m = 1;
		for(i = 0 ; i < n ; i++ ) {
			m = m * (b[i] % N);
		}
		pop_r(r,rn,n-1);
		sum = r[0];
		for(i = 1 ; i < n-1 ; i++) {
			sum = sum + r[i];
			sum = sum % N;
		}
		i = 0;
		j = n-1;
		rem = 0;
		while(i < j) {
			temp = s[j] - s[i];
			temp *= sum;
			sum = sum - r[j-1] - r[i];
			temp = temp % N;
			rem = rem + temp;
			rem = rem % N;
			i++;
			j--;
		}
		rem = rem * m;
		rem = rem % N;
		printf("%llu\n", rem);
	}
	return 0;
}