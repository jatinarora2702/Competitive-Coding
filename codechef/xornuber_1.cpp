#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long int n, t, k, f, p, k1;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		f = 0;
		if(n == 1){
			k1 = 2;
			f = 1;
		}
		else{
			k1 = 0;
			k = 1;
			p = 1;
			while(true){
				if(k > n)
					break;
				if(k == n){
					f = 1;
					break;
				}
				k1 = k;
				p *= 2;
				k = k + p; 
			}
			
		}
		if(f == 0)
			printf("-1\n");
		else
			printf("%lld\n", k1);
	}
	return 0;
}