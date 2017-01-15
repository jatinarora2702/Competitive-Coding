#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, x, cnt, sch, zcnt;
	scanf("%d", &n);
	cnt = 0;
	sch = 0;
	zcnt = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		if(sch == 0){
			if(x == 1){
				cnt++;
				sch = 1;
			}
		}
		else{
			if(x == 0){
				zcnt++;
			}
			else{
				cnt++;
				if(zcnt == 1){
					cnt++;
					zcnt = 0;
				}
			}
			if(zcnt == 2){
				zcnt = 0;
				sch = 0;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}