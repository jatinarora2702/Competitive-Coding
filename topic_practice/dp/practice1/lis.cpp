#include <iostream>
#include <cstdio>
#define N 1000
using namespace std;
int a[N], dp[N], s[N], b[N];
int main() {
	int n, maxm, k;
	printf("Enter the no. of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the array:\n");
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	printf("The longest increasing seq. is of length: ");
	dp[0] = 1;
	s[0] = -1;
	for(int i = 1 ; i < n ; i++){
		dp[i] = 0;
		s[i] = -1;
		for(int j = 0 ; j < i ; j++){
			if(a[i] > a[j] && dp[i] < dp[j]){
				dp[i] = dp[j];
				s[i] = j;
			}
		}
		dp[i]++;
	}
	maxm = 0;
	for(int i = 1 ; i < n ; i++)
		maxm = (dp[maxm] < dp[i]) ? i : maxm;
	printf("%d\n", dp[maxm]);
	printf("And the seq. is:\n");
	k = 0;
	while(maxm != -1){
		b[k++] = a[maxm];
		maxm = s[maxm];
	}
	k--;
	while(k >= 0) {
		printf("%d ", b[k]);
		k--;
	}
	printf("\n");
	return 0;
}