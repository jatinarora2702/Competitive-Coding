#include <iostream>
#include <cstdio>
#define N 100
using namespace std;
char a[N], b[N];
int dp[N][N], ci, cd, cr;
int getcost(char *a, char *b, int i, int j){
	if(i < 0)
		return (j+1)*ci;
	if(j < 0)
		return (i+1)*cd;
	if(dp[i][j] == -1){
		if(a[i] == b[j]){
			dp[i][j] = getcost(a, b, i-1, j-1);
		}
		else{
			dp[i][j] = min(cr + getcost(a, b, i-1, j-1), ci + getcost(a, b, i, j-1));
			dp[i][j] = min(dp[i][j], cd + getcost(a, b, i-1, j));
		}
	}
	return dp[i][j];
}
int main(){
	int m, n, k;
	printf("Enter the length of orig. string: ");
	scanf("%d", &m);
	printf("Enter the length of new string: ");
	scanf("%d", &n);
	printf("Enter the costs:\n");
	printf("Insert: ");
	scanf("%d", &ci);
	printf("Delete: ");
	scanf("%d", &cd);
	printf("Replace: ");
	scanf("%d", &cr);
	printf("Enter the orig. string: ");
	scanf("%s", a);
	printf("Enter the new string: ");
	scanf("%s", b);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			dp[i][j] = -1;
	}
	k = getcost(a, b, m-1, n-1);
	printf("min. edit distance is: %d\n", k);
	return 0;
}