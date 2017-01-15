#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int t, a, b, cnt, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		x = a ^ b;
		cnt = 0;
		for(int i = 1 ; i <= x ; i<<=1)
			if(i & x) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}