#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int t, n, *a, cnt, max;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		sort(a,a+n);
		cnt = 0;
		max = 0;
		for(int i = 0 ; i < n ; i++){
			if(i+1 < n and i+2 < n and a[i+1] - a[i] == 1 and a[i+2] - a[i+1] == 1){
				cnt++;
				i = i + 2;
			}
			else if(i+1 < n and a[i+1] - a[i] == 1){
				cnt++;
				i = i + 1;
			}
			else{
				cnt++;
			}
		}
		for(int i = 0 ; i < n ; i++){
			if(i+1 < n and a[i+1] - a[i] == 1){
				max++;
				i = i + 1;
			}
			else{
				max++;
			}
		}
		printf("%d %d\n", cnt, max);
	}
	return 0;
}