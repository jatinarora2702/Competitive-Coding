#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, t, k, f, p, k1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		k1 = 0;
		k = 1;
		f = 0;
		p = 0;
		while(true){
			if(k > n)
				break;
			if(k == n)
				f = 1;
			k1 = k;
			p *= 2;
			k = k + p; 
		}
		if(f == 0)
			printf("-1\n");
		else
			printf("&d\n", k1);
	}
	return 0;
}