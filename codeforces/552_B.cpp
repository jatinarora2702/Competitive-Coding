#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int ulli;
void print(int *a, int n){
	for(int i = 0 ; i < n ; i++)
		printf("%d ", a[i]);
	cout << endl;
}
void printlld(ulli *a, int n){
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main(){
	int n, d, rem, n1, k, *a;
	ulli *sum, *dp, sums;
	scanf("%d", &n);
	n1 = n;
	d = 0;
	while(n != 0){
		d++;
		n /= 10;
	}
	//cout << d << endl;
	a = new int[d-1];
	//sum = new ulli[d-1];
	dp = new ulli[d-1];
	a[0] = 9;
	for(int i = 1 ; i < d-1 ; i++){
		a[i] = a[i-1] * 10 + 9;
	}
	//print(a,d-1);
	dp[0] = a[0];
	for(int i = 1 ; i < d-1 ; i++){
		dp[i] = a[i]-a[i-1];
	}
	//printlld(dp, d-1);
	sums = 0;
	for(int i = 0 ; i < d-1 ; i++){
		sums += dp[i]*(i+1);
	}
	//cout << sums;
	k = 1;
	for(int i = 0 ; i < d-1 ; i++)
		k *= 10;
	//cout << k << endl;
	sums += (ulli)(n1-k+1)*d;
	cout << sums;
	return 0;
}