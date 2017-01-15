#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m, x_low, x_high, ans;
	scanf("%d%d", &n, &m);
	if(m == 1)
		ans = (n != 1) ? m+1 : 1;
	else if(m == n)
		ans = (n != 1) ? n-1 : 1;
	else{
		x_low = m-1;
		x_high = m+1;
		ans = (x_low < n-x_high+1) ? x_high : x_low; 
	}
	printf("%d", ans);
	return 0;
}