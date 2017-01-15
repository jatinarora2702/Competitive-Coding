#include <stdio.h>
int main(){
	int t, a, b, cnt, x, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		x = a ^ b;
		cnt = 0;
		for(i = 1 ; i <= x ; i<<=1)
			if(i & x) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}