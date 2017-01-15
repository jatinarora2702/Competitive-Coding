#include <bits/stdc++.h>
#define PB push_back
#define N 50000000
using namespace std;
typedef long long int lli;
vector < int > v;
int a[N];

lli numfac(lli n, int &fa) {
	int i, k;
	lli f, num;
	f = 2LL;
	fa = 0;
	while(n % f == 0) {
		fa++;
		f *= 2LL;
	}
	fa++;
	num = (lli)fa;
	for(i = 1 ; i < v.size() ; i++) {
		if((lli)v[i] > n)
			break;
		k = 0;
		f = (lli)v[i];
		while(n % f == 0) {
			k++;
			f *= (lli)v[i];
		}
		num *= (lli)(k+1);
	}
	return num;
}

int main() {
	int i, j, k1, k2, p1, p2, k;
	v.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			v.PB(i);
			if(i <= sqrt(N)) {
				for(j = i*i ; j < N ; j+=i)
					a[j] = 1;
			}
		}
	}
	k1 = 1;
	p1 = 1;
	for(i = 2 ; i < N ; i++) {
		k2 = numfac((lli)i, p2);
		// printf("p2=%d\n", p2);
		k = k1 * k2;
		if(p2 > 1){
			k /= p2;
			k *= (p2-1);
		}
		else{
			k /= p1;
			k *= (p1-1);
		}
		if(k > 500) {
			cout << (lli)(i*(i-1))/(lli)2 << "\n";
			break;
		}
		k1 = k2;
		p1 = p2;
	}
	return 0;
}