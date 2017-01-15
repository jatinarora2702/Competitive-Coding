#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
int main() {
	int n, *a, k;
	ulli s;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	sort(a,a+n);
	s = 0;
	for(int i = 0 ; i < n ; i++){
		if(s > a[i])
			k++;
		else
			s += (ulli)a[i];
	}
	printf("%d", n-k);
	return 0;
}