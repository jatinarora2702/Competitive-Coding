#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, n, *dpf, *dpb, cnt;
	int *a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		dpf = new int[n];
		dpb = new int[n];
		dpf[0] = a[0];
		for(int i = 1 ; i < n ; i++){
			dpf[i] = dpf[i-1] ^ a[i];
		}
		dpb[0] = a[n-1];
		for(int i = 1 ; i < n ; i++){
			dpb[i] = dpb[i-1] ^ a[n-1-i];
		}
		cnt = 0;
		if(dpb[n-2] == 0)
			cnt++;
		for(int i = 1 ; i < n-1 ; i++){
			if(dpf[i-1] ^ dpb[n-i-2] == 0)
				cnt++;
		}
		if(dpf[n-2] == 0)
			cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}