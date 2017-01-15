#include <bits/stdc++.h>
#define PB push_back
#define N 30000
using namespace std;
int a[N], b[N];
vector < int > p, v;
int main() {
	int i, j, s, t, f;
	p.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			p.PB(i);
			if(i <= sqrt(N)) {
				for(j = i*i ; j < N ; j+=i)
					a[j] = 1;
			}
		}
	}
	for(i = 1 ; i < N ; i++) {
		s = 1;
		for(j = 0 ; j < p.size() ; j++) {
			if(p[j] > i)
				break;
			t = 0;
			f = 1;
			while(i % f == 0) {
				t += f;
				f *= p[j];
			}
			s *= t;
		}
		s -= i;
		if(i < s)
			v.PB(i);
	}
	for(i = 0 ; i < v.size() ; i++) {
		for(j = i ; j < v.size() ; j++) {
			if(v[i]+v[j] > N)
				break;
			b[v[i]+v[j]] = 1;
		}
	}
	s = 0;
	for(i = 0 ; i < N ; i++) {
		if(b[i] == 0){
			printf("%d ", i);
			s += i;
		}
	}
	printf("\n");
	printf("%d\n", s);
	return 0;
}