#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n, *a, *dp, max, *last;
	printf("Enter the no. of elements in the array : ");
	scanf("%d", &n);
	a = new int[n];
	dp = new int[n];
	last = new int[n];
	max = 1;
	printf("Enter the array :\n");
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	dp[0] = 0;
	last[0] = a[0];
	for(int i = 1 ; i < n ; i++){
		l = max;
		f = 1;
		while(f <= l){
			m = (f+l) / 2;
			if(a[dp[m-1]] <= a[i])
				f = m+1;
			else
				l = m-1;
		}
		last[i] = 
		dp[f] = ;
		if()
	}
	for(int i = 0 ; i < n ; i++)
		printf("%d ", a[i])
}