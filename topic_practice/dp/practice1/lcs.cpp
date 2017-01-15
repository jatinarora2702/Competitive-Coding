#include <iostream>
#include <cstdio>
#define N 1000
using namespace std;
char a[N], b[N], c[N], dp[N][N], lcs[N];
int s[N][N];
int getlcs(char *a, int i, char *b, int j){
	if(i < 0 || j < 0)
		return 0;
	if(dp[i][j] == -1) {
		if(a[i] == b[j]){
			dp[i][j] = 1 + getlcs(a, i-1, b, j-1);
			s[i][j] = 0;
		}
		else{
			int v1 = getlcs(a, i, b, j-1);
			int v2 = getlcs(a, i-1, b, j);
			dp[i][j] = max(v1, v2);
			s[i][j] = (v1 > v2) ? -1 : 1;
		}
	}
	return dp[i][j];
}
int main(){
	int n, m, k, i1, j1, k1;
	printf("Enter the length of 1st seq: ");
	scanf("%d", &m);
	for(int i = 0 ; i < m ; i++)
		scanf(" %c", &a[i]);
	printf("Enter the length of the 2nd seq: ");
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf(" %c", &b[i]);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			dp[i][j] = -1;
	}
	k = getlcs(a, m-1, b, n-1);
	printf("Length of the longest common subseq. is : %d\n", k);
	printf("And the seq. is :\n");
	i1 = m-1;
	j1 = n-1;
	k1 = 0;
	while(i1 >= 0 && j1 >= 0){
		if(s[i1][j1] == 0){
			lcs[k1++] = a[i1];
			i1--;
			j1--;
		}
		else if(s[i1][j1] == 1)
			i1--;
		else
			j1--;
	}
	k1--;
	while(k1 >= 0){
		printf("%c", lcs[k1]);
		k1--;
	}
	printf("\n");
	return 0;
}