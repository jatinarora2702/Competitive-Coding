#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n, *a, *dp0, *dp1, *tmp0, *tmp1;
	scanf("%d", &n);
	a = new int[n];
	dp0 = new int[n];
	dp1 = new int[n];
	tmp1 = new int[n];
	tmp2 = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	dp0[0] = a[n-1];
	dp1[0] = a[0];
	for(int i = 1 ; i < n ; i++){
		tmp1[0] = a[0];
		tmp0[0] = a[i];
	}
}