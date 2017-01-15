/*
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, s[10][10], **dp, sum;
	printf("Enter the length of final string : ");
	dp = new int*[10];
	for(int i = 0 ; i < 10 ; i++){
		dp[i] = new int[n];
	}
	s[0][] = {0,8,-1};
	s[1][] = {1,2,4,-1};
	s[2][] = {2,1,3,5,-1};
	s[3][] = {3,2,6,-1};
	s[4][] = {4,1,5,7,-1};
	s[5][] = {5,2,4,6,8,-1};
	s[6][] = {6,3,5,9,-1};
	s[7][] = {7,4,8,-1};
	s[8][] = {8,5,7,9,0,-1};
	s[9][] = {9,6,8,-1};

	for(int i = 0 ; i < 10 ; i++)
		dp[i][0] = 1;
	for(int k = 1 ; k < n ; k++){
		for(int i = 0 ; i < 10 ; i++){
			dp[i][k] = 0;
			for(int j = 0 ; s[i][j] != -1 ; j++){
				dp[i][k] += dp[s[i][j]][k-1];
			}
		}
	}
	sum = 0;
	for(int i = 0 ; i < 10 ; i++)
		sum += dp[i][n-1];
	printf("No. of possible n length strings is : %d\n", sum);
	return 0;	
}
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, **dp, sum;
	printf("Enter the length of final string : ");
	scanf("%d", &n);
	dp = new int*[10];
	for(int i = 0 ; i < 10 ; i++){
		dp[i] = new int[n];
	}
	int s[][10] = {{0,8,-1},{1,2,4,-1},{2,1,3,5,-1},{3,2,6,-1},{4,1,5,7,-1},{5,2,4,6,8,-1},{6,3,5,9,-1},{7,4,8,-1},{8,5,7,9,0,-1},{9,6,8,-1}};
	for(int i = 0 ; i < 10 ; i++)
		dp[i][0] = 1;
	for(int k = 1 ; k < n ; k++){
		for(int i = 0 ; i < 10 ; i++){
			dp[i][k] = 0;
			for(int j = 0 ; s[i][j] != -1 ; j++){
				dp[i][k] += dp[s[i][j]][k-1];
			}
		}
	}
	sum = 0;
	for(int i = 0 ; i < 10 ; i++)
		sum += dp[i][n-1];
	printf("No. of possible n length strings is : %d\n", sum);
	return 0;	
}