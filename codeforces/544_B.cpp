#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n, k, sq, max, f;
	scanf("%d%d", &n, &k);
	sq = n * n;
	max = (sq+1)/2;
	if(k > max)
		printf("NO");
	else{
		printf("YES\n");
		int cnt = 0;
		for(int i = 0 ;i < n ;i++){
			f = ((i%2) == 0 and cnt < k) ? 1 : 0;
			for(int j = 0 ; j < n ; j++){
				printf("%c", (f == 1) ? 'L' : 'S');
				if(f == 1){
					cnt++;
					if(cnt == k){
						cnt++;
						f ^= 1;
					}	
				} 
				f = (cnt < k) ? (f^1) : f;
			}
			printf("\n");
		}
	}
	return 0;
}