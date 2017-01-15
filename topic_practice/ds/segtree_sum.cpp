#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int sg_constr(int *arr, int *st, int ss, int se, int si){
	if(ss == se)
		st[si] = arr[ss];
	else{
		int mid = (ss + se) / 2;
		st[si] = sg_constr(arr, st, ss, mid, 2*si+1) + sg_constr(arr, st, mid+1, se, 2*si+2);
	}
	return st[si];
}
int get_sum(int *st, int ss, int se, int qs, int qe, int si){
	if(qs <= ss and se <= qe)
		return st[si];
	else if(qs > se or qe < ss)
		return 0;
	int mid = (ss + se) / 2;
	return get_sum(st, ss, mid, qs, qe, 2*si+1) + get_sum(st, mid+1, se, qs, qe, 2*si+2);
}
void update(int *st, int ss, int se, int si, int i, int diff){
	if(i < ss or i > se)
		return;
	st[si] += diff;
	if(ss != se){
		st[si] += diff;
		int mid = (ss + se) / 2;
		update(st, ss, mid, 2*si+1, i, diff);
		update(st, mid+1, se, 2*si+2, i, diff);
	}
}
int main() {
	int n, *arr, ns, sum, *st;
	scanf("%d", &n);
	arr = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	ns = 2 * pow(2, ceil(log2(n))) - 1;
	st = new int[ns];
	sum = sg_constr(arr, st, 0, n-1, 0);
	printf("%d\n", get_sum(st, 0, n-1, 1, 3, 0));
	update(st, 0, n-1, 0, 1, 10 - arr[1]);
	printf("%d\n", get_sum(st, 0, n-1, 1, 3, 0));
	return 0;
}