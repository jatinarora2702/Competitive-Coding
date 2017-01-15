#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 100
using namespace std;
int main() {
	int n, m, k, **dp, **s, it1, it2, it3, m1, m2, val;
	char *a, *b, *c;
	a = new char[N];
	b = new char[N];
	c = new char[N];
	scanf("%s%s", a, b);
	m = strlen(a);
	n = strlen(b);
	dp = new int*[m+1];
	s = new int*[m+1];
	for(int i = 0 ; i <= m ; i++){
		dp[i] = new int[n+1];
		s[i] = new int[n+1];
		dp[i][0] = 0;
		for(int j = 0 ; j <= n ; j++)
			s[i][j] = 0;
	}
	for(int j = 0 ; j <= n ; j++)
		dp[0][j] = 0;
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				s[i][j] = 3;
			}
			else{
				m1 = dp[i-1][j];
				m2 = dp[i][j-1];
				s[i][j] = (m1 > m2) ? 1 : 2;
				dp[i][j] = (m1 > m2) ? m1 : m2;
			}
		}
	}
	it1 = m;
	it2 = n;
	it3 = 0;
	printf("LCS : %d : ", dp[m][n]);
	while(true){
		if(it1 < 0 || it2 < 0)
			break;
		val = s[it1][it2];
		if(val == 0)
			break;
		if(val == 3){
			c[it3] = a[it1-1];
			it3++;
			it1--;
			it2--;
		}
		else if(val == 2){
			it2--;
		}
		else if(val == 1){
			it1--;
		}
	}
	for(int i = it3-1 ; i >= 0 ; i--)
		printf("%c", c[i]);
	printf("\n");
	return 0;
}