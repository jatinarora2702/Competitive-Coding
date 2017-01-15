#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
int main() {
	int n, cnt, *a;
	ulli sum;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
	scanf("%d", &a[i]);
	}
	sort(a, a+n);
	sum = 0;
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
	if(sum > a[i])
		cnt++;
	sum += (ulli)a[i];
	}
	printf("%d", n-cnt);
	return 0;
}