#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, m, k, i, j, cnt;
	scanf("%d%d%d", &n, &m, &k);
	i = j = 0;
	cnt = 0;
	for(int i1 = 0 ; i1 < k-1 ; i1++){
		cnt += 2;
		printf("2 ");
		for(int j1 = 0 ; j1 < 2 ; j1++){
			printf("%d %d ", i+1, j+1);
			if(i%2 == 0){
				if(j+1 < m)
					j++;
				else
					i++;
			}
			else{
				if(j-1 >= 0)
					j--;
				else
					i++;
			}
		}
		printf("\n");
	}
	cnt = m*n - cnt;
	if(cnt > 0)
		printf("%d ", cnt);
	for(int j1 = 0 ; j1 < cnt ; j1++){
		printf("%d %d ", i+1, j+1);
		if(i%2 == 0){
			if(j+1 < m)
				j++;
			else
				i++;
		}
		else{
			if(j-1 >= 0)
				j--;
			else
				i++;
		}
	}
	return 0;
}