#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int t, n, x, xold;
	ulli max;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		max = 0;
		xold = 0;
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &x);
			if(x > xold)
				max += ulli(x - xold);
			xold = x;
		}
		cout << max << endl;
	}
	return 0;
}