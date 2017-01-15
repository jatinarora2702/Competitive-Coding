#include <bits/stdc++.h>
using namespace std;
void printi(int *lis, int *si, int *a, int pos){
	if(pos == -1)
		return;
	if(si[pos] == -1){
		printf("%d ", a[pos]);
		return;
	}
	printi(lis, si, a, si[pos]);
	printf("%d ", a[pos]);
}
void printd(int *lds, int *sd, int *a, int pos){
	if(sd[pos] == -1){
		printf("%d ", a[pos]);
		return;
	}
	printf("%d ", a[pos]);
	printd(lds, sd, a, sd[pos]);
}
int main() {
	int n, *a, *lis, *lds, *si, *sd, max, v, pos;
	printf("Enter the no. of elements in the array : ");
	scanf("%d", &n);
	a = new int[n];
	printf("Enter the array : ");
	for(int i =  0 ; i < n ; i++ ) {
		scanf("%d", &a[i]);
	}
	lis = new int[n];
	lds = new int[n];
	si = new int[n];
	sd = new int[n];
	lis[0] = lds[n-1] = 1;
	si[0] = sd[n-1] = -1;
	for(int i = 1 ; i < n ; i++ ) {
		lis[i] = 0;
		si[i] = -1;
		for(int j = 0 ; j < i ; j++ ) {
			if(a[j] < a[i] and lis[i] < lis[j]){
				lis[i] = lis[j];
				si[i] = j;
			}
		}
		lis[i]++;
	}
	for(int i = n-2 ; i >=0 ; i-- ) {
		lds[i] = 0;
		sd[i] = -1;
		for(int j = i+1 ; j < n ; j++ ) {
			if(a[j] <= a[i] and lds[i] < lds[j]){
				lds[i] = lds[j];
				sd[i] = j;
			}
		}
		lds[i]++;
	}
	max = lds[0];
	pos = 0;
	for(int i = 1 ; i < n ; i++ ) {
		v = lis[i] + lds[i] - 1;
		if(max < v){
			max = v;
			pos = i;
		}
	}
	printf("Max. bitonic seq. has length : %d\n", max);
	printi(lis, si, a, si[pos]);
	printf("%d ", a[pos]);
	printd(lis, sd, a, sd[pos]);
	printf("\n");
	return 0;
}