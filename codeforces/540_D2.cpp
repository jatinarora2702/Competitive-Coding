#include <iostream>
#include <stdio.h>
using namespace std;
double dp[101][101][101];
inline double val(int n){
	double d;
	d = n * (n-1);
	d = d / (double)2;
	return d;
}
int main(){
	int r, s, p, i, j, k;
	double sum, v, sarr[3];
	scanf("%d%d%d", &r, &p, &s);
	r, s, p;
	dp[r][p][s] = 1;
	for(int i = r ; i >= 0 ; i--){
		for(int j = p ; j >= 0 ; j--){
			for(int k = s ; k >= 0 ; k--){
				cout << "i=" << i << " j=" << j << " k=" << k << endl;
				if(i == r and j == p and k == s)
					continue;
				dp[i][j][k] = 0;
				if(i == 0 and j == 0 and k == 0)
					continue;
				v = val(i+j+k+1);
				cout << "v=" << v << endl;
				if(i < r)
					{dp[i][j][k] += dp[i+1][j][k] * (double)((i+1) * j) / v;  cout << "a\n"; }
				if(j < p)
					{dp[i][j][k] += dp[i][j+1][k] * (double)((j+1) * k) / v; cout << "b\n"; }
				if(k < s)
					{dp[i][j][k] += dp[i][j][k+1] * (double)((k+1) * i) / v; cout << "c\n"; }
				cout << dp[i][j][k] << endl;	
			}
		}
	}
	sum = 0;
	for(int  i= 0 ; i < 3; i++)
		sarr[i] = 0;
	/*for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < p ; j++)
			for(int k = 0 ; k < s ; k++)
				sum += dp[i][j][k];*/
	for(int i = 0 ; i < r ; i++)
		sarr[0] += dp[i][0][0];
	for(int i = 0;  i < p ; i++)
		sarr[1] += dp[0][i][0];
	for(int i = 0 ; i < s ; i++)
		sarr[2] += dp[0][0][i];
	cout << "result : \n";
	for(int i = 0 ; i < 3 ; i++)
		cout << sarr[i] << endl;
	sum = sarr[0] + sarr[1] + sarr[2];
	printf("%.12lf %.12lf %.12lf", sarr[0]/sum, sarr[1]/sum, sarr[2]/sum);
	return 0;
}