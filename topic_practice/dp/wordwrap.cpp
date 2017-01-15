#include <bits/stdc++.h>
#define INF 1000000007
#define MAX 1000
using namespace std;
int main() {
	char *s;
	s = new char[MAX];
	int n, *a, j, m, *dp, sum, min, v, cnt;
	printf("Enter the string to wrap :\n");
	gets(s);
	printf("Enter the line length : ");
	scanf("%d", &m);
	n = 0;
	for(int i = 0 ; s[i] != '\0'  ; i++) {
		if(s[i] == ' ')
			n++;
	}
	n++;
	cout << "n=" << n << endl;
	a = new int[n];
	j = 0;
	for(int i = 0 ; i < n ; i++ ) {
		a[i] = 0;
	}
	for(int i = 0 ; s[i] != '\0' ; i++) {
		if(s[i] != ' ')
			a[j]++;
		else
			j++;
	}
	for(int i = 0 ; i < n ; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	dp = new int[n];
	for(int i = 0 ; i < n ; i++) {
		j = 0;
		sum = 0;
		min = INF;
		while(1){
			if(n-i-1+j >= n)
				break;
			if(sum != 0)
				sum++;
			sum += a[n-i-1+j];
			if(sum > m)
				break;
			v = (m-sum)*(m-sum)*(m-sum);
			if(i-j-1 >= 0)
				v += dp[i-j-1];
			if(v < min){
				min = v;
				cnt = sum;
			}
			j++;
		}
		dp[i] = min;
		cout << "dp[i]=" << dp[i] << " cnt=" << cnt << endl;
	}
	printf("The min. word wrap sum is : %d\n", dp[n-1]);
	return 0;
}