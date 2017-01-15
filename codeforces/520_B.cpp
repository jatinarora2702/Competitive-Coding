#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int m, n, f;
	scanf("%d%d", &n, &m);
	f = 0;
	while(m > n){
		f++;
		if(m%2 != 0)
			f++;
		m = (m+1)/2;
	}
	printf("%d", f + (n-m));
	return 0;
}