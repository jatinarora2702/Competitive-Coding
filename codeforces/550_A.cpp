#include <iostream>
#include <stdio.h>
#define N 100001
using namespace std;
int main(){
	int i, f1, f2, f3, f4;
	char s[N], dp[N];
	scanf("%s", s);
	for(i = 0 ; s[i] != '\0' ; i++){
		if(s[i] == 'A' and s[i+1] == 'B')
			dp[i] = '1';
		else if(s[i] == 'B' and s[i+1] == 'A')
			dp[i] = '2';
		else
			dp[i] = '0';
	}
	dp[i] = '\0';
	f1 = f2 = f3 = f4 = 0;
	for(i = 0 ; dp[i] != '\0' ; i++){
		if(dp[i] == '1' and dp[i+1] == '2'){
			f3++;
			i+=2;
		}
		else if(dp[i] == '2' and dp[i+1] == '1'){
			f4++;
			i+=2;
		}
		else if(dp[i] == '1')
			f1++;
		else if(dp[i] == '2')
			f2++;
	}
	if((f3+f4 > 1) or (f1 > 0 and f2+f3+f4 > 0) or (f2 > 0 and f1+f3+f4 > 0))
		printf("YES");
	else
		printf("NO");
	return 0;
}