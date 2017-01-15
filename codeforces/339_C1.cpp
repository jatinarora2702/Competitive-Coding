#include <bits/stdc++.h>
using namespace std;
int dp[25][15][1005], s[25][15][1005], m;
char str[15];
int getans(int bal, int lst, int iter){
	int val;
	if(dp[bal][lst][iter] == 0){
		if(iter >= m){
			dp[bal][lst][iter] = 1;
			s[bal][lst][iter] = -1;
		}
		else{
			if(iter % 2 == 0){
				val = 10 - bal;
				if(val < 0){
					dp[bal][lst][iter] = -1;
					s[bal][lst][iter] = -1;
				}
				else{
					dp[bal][lst][iter] = -1;
					s[bal][lst][iter] = -1;
					for(int i = val+1 ; i <= 10 ; i++){
						if(str[i-1] == '1' && i != lst){
							dp[bal][lst][iter] = getans(bal+i, i, iter+1);
							if(dp[bal][lst][iter] == 1){
								s[bal][lst][iter] = i;
								break;
							}
						}
					}
				}
			}
			else{
				val = bal - 10;
				if(val < 0){
					dp[bal][lst][iter] = -1;
					s[bal][lst][iter] = -1;
				}
				else{
					dp[bal][lst][iter] = -1;
					s[bal][lst][iter] = -1;
					for(int i = val+1 ; i <= 10 ; i++){
						if(str[i-1] == '1' && i != lst){
							dp[bal][lst][iter] = getans(bal-i, i, iter+1);
							if(dp[bal][lst][iter] == 1){
								s[bal][lst][iter] = i;
								break;
							}
						}
					}
				}
			}
		}
	}
	return dp[bal][lst][iter];
}
int main() {
	int k, x, y;
	scanf("%s %d", str, &m);
	k = getans(10, 0, 0);
	if(k == 1){
		printf("YES\n");
		x = 10;
		y = 0;
		for(int i = 0 ; i < m ; i++){
			y = s[x][y][i];
			printf("%d ", y);
			if(i%2 == 0)
				x = x+y;
			else
				x = x-y;
		}
	}
	else
		printf("NO\n");
	return 0;
}