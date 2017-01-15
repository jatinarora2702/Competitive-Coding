#include <bits/stdc++.h>
#define N 10000
using namespace std;
int a[N];
int main() {
	int n, l, d;
	scanf("%d%d", &n, &l);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	d = 0;
	for(int i = 0 ; i < n-1 ; i++){
		if(d < (a[i+1]-a[i]))
			d = a[i+1] - a[i];
	}
	if(d <= 2 * max(a[0], l-a[n-1]))
		printf("%d", max(a[0], l-a[n-1]));
	else{
		printf("%d", d/2);
		if(d % 2 == 1)
			printf(".5");
	}
	return 0;
}