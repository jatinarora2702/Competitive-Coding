#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
int check_if_palin(string s){
	int i, j;
	i = 0;
	j = s.length() - 1;
	while(i < j){
		if(s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
int main() {
	string s;
	int n, **dp, min, v;
	printf("Enter the string to find the min. palindrome partitioning :\n");
	cin >> s;
	n = s.length();
	cout << "n=" << n << endl;
	dp = new int*[n];
	for(int i = 0 ; i < n ; i++ ) {
		dp[i] = new int[n];
	}
	for(int i = 0 ; i < n ; i++ ) {
		dp[i][i] = 0;
	}
	for(int k = 1 ; k < n ; k++ ) {
		for(int i = 0 ; i < n-k ; i++ ) {
			int f = check_if_palin(s.substr(i,k+1));
			cout << s.substr(i,k) << " f = " << f << endl;
			if(f == 1)
				dp[i][i+k] = 0;
			else{
				min = INF;
				for(int j = i ; j < i+k ; j++ ) {
					v = dp[i][j] + dp[j+1][i+k] + 1;
					if(v < min)
						min = v;
				}
				dp[i][i+k] = min;
			}
		}
	}
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			printf("%d  ", dp[i][j]);
		}
		printf("\n");
	}
	printf("Min. no. of palindromic partitions are : %d\n", dp[0][n-1]);
	return 0;
}