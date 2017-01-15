#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N], collected[N];
int main() {
	int n, f, cnt, dir, info;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	cnt = -1;
	f = 1;
	dir = 0;
	info = 0;
	while(f == 1){
		cnt++;
		if(dir == 0){
			f = 0;
			for(int i = 0 ; i < n ; i++){
				if(collected[i] == 0){
					f = 1;
					if(a[i] <= info){
						collected[i] = 1;
						info++;
					}
				}
			}
			dir = 1;
		}
		else{
			f = 0;
			for(int i = n-1 ; i >= 0 ; i--){
				if(collected[i] == 0){
					f = 1;
					if(a[i] <= info){
						collected[i] = 1;
						info++;
					}
				}
			}
			dir = 0;
		}
	}
	printf("%d", cnt-1);
	return 0;
}