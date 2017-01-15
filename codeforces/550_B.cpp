#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n, *c, l, r, x, cnt, k, sum;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	c = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &c[i]);
	}
	sort(c, c+n);
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = n-1 ; j > i ; j--){
			if(c[j]-c[i] >= x){
				sum = c[i]+c[j];
				k = j-1;
				while(sum < l and k > i){
					sum += c[k];
					k--;
				}
				if(k > i){
					cnt++;
					k++;
					for(int l = i+1 ; l < k ; l++){
						sum += c[l];
						if(sum <= r)
							cnt++;
						else
							break;
					}
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}