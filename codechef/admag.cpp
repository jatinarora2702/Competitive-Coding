#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int lli;
int main(){
	int t, c;
	lli fib[90], n;
	fib[0] = 1;
	fib[1] = 2;
	for(int i = 2 ; i < 89 ; i++)
		fib[i] = fib[i-1] + fib[i-2];
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		for(c = 0 ; c < 89 ; c++)
			if(fib[c] > n)
				break;
		printf("%d\n", c);
	}
	return 0;
}