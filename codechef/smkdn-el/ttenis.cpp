#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	int t, n, cnt2, cnt1, f;
	char s[101];
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		cnt2 = cnt1 = 0;
		f = 0;
		for(int i = 0 ; s[i] != '\0' ; i++){
			if(s[i] == '0')
				cnt2++;
			else
				cnt1++;
			if(f == 1 and abs(cnt1 - cnt2) == 2)
				break;
			if(f == 0 and (cnt1 == 11 or cnt2 == 11))
				break;
			if(cnt2 == 10 and cnt1 == 10){
				f = 1;
			}
		}
			if(cnt1 > cnt2)
				printf("WIN\n");
			else
				printf("LOSE\n");
	}
	return 0;
}