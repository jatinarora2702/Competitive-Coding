#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if(n % 2 != 0)
		printf("0\n");
	else{
		n /= 2;
		printf("%d", (n+1)/2-1);
	}
	return 0;
}