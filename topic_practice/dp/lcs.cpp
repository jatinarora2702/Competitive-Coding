#include <bits/stdc++.h>
using namespace std;
void print(string a, char **s, int m, int i, int j) {
	if(i < 0 or j < 0) 
		return;
	if(s[i][j] == 'a')
		print(a,s,m,i-1,j);
	else if(s[i][j] == 'b')
		print(a,s,m,i,j-1);
	else {
		print(a,s,m,i-1,j-1);
		printf("%c",a[j]);
	}
}
int max(int a, int b) {
	if(a > b) 
		return a;
	else
		return b;
}
int main() {
	string a,b;
	cout << "Enter strings :\n";
	cin >> a >> b;
	int m,n;
	m = a.size();
	n = b.size();
	int **dp = new int*[n];
	char **s = new char*[n];
	for(int i = 0 ; i < n ; i++ ) {
		dp[i] = new int[m];
		s[i] = new char[n];
	}
	if(a[0] == b[0]){
		dp[0][0] = 1;
		s[0][0] = 'c';
	}
	else{
		dp[0][0] = 0;
		s[0][0] = 'a';
	}
	for(int i = 1 ; i < n ; i++ ) {
		dp[0][i] = dp[0][i-1];
		if(b[i] == a[0]){
			dp[0][i] += 1;
			s[0][i] = 'c';
		}
		else{
			s[0][i] = 'b';
		}
	}
	for(int i = 1 ; i < m ; i++ ) {
		dp[i][0] = dp[i-1][0];
		if(a[i] == b[0]){
			dp[i][0] += 1;
			s[i][0] = 'c';
		}
		else{
			s[i][0] = 'a';
		}
	}
	for(int i = 1 ; i < n ; i++ ) {
		for(int j = 1 ; j < m ; j++ ) {
			if(b[i] == a[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				s[i][j] = 'c';
			}
			else{ 
				dp[i][j] = dp[i-1][j];
				s[i][j] = 'a';
				if(dp[i][j-1] > dp[i-1][j]) {
					dp[i][j] = dp[i][j-1];
					s[i][j] = 'b';
				}
			}
		}
	}
	/*
	cout << "dp array :\n";
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < m ; j++ ) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "s array :\n";
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < m ; j++ ) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	*/
	printf("Length of the longest common subsequence is : %d\n",dp[n-1][m-1]);
	printf("And the sequence is : ");
	print(a,s,m,n-1,m-1);
	cout << endl;
	return 0;
}