#include <iostream>
#include <stdio.h>
#include <cmath>
#define INF 1000000007
using namespace std;
int st_constr(int *arr, int *st, int ss, int se, int si){
	if(ss == se)
		st[si] = arr[ss];
	else{
		int mid = (ss + se) / 2;
		st[si] = min(st_constr(arr, st, ss, mid, 2*si+1), st_constr(arr, st, mid+1, se, 2*si+2));
	}
	return st[si];
}
int get_min(int *st, int ss, int se, int qs, int qe, int si){
	if(ss >= qs and se <= qe)
		return st[si];
	else if(qs > se or qe < ss)
		return INF;
	else{
		int mid = (ss + se) / 2;
		return min(get_min(st, ss, mid, qs, qe, 2*si+1), get_min(st, mid+1, se, qs, qe, 2*si+2));
	}
}
int main() {
	int n, *arr, *st, ns;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	ns = 2 * pow(2, ceil(log2(n))) - 1;
	st = new int[ns];
	st_constr(arr, st, 0, n-1, 0);
	printf("%d\n", get_min(st, 0, n-1, 1, 5, 0));
	return 0;
}