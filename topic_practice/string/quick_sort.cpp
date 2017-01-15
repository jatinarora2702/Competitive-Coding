#include <iostream>
#include <stdio.h>
using namespace std;
int partition(int *a, int n){
	int i, j, temp;
	i = 1;
	j = n-1;
	while(i < j){
		while(j > 0 && a[j] > a[0]) j--;
		while(i < j && a[i] <= a[0]) i++;
		if(i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	if(a[0] > a[j]){
		temp = a[0];
		a[0] = a[j];
		a[j] = temp;		
	}
	return j;
}
void quicksort(int *a, int n){
	if(n < 2)
		return;
	int p = partition(a, n);
	quicksort(a, p);
	quicksort(a+p+1, n-p-1);
}
int main() {
	int n, *a;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n;  i++)
		scanf("%d", &a[i]);
	quicksort(a, n);
	for(int i= 0 ;  i < n ; i++)
		printf("%d ", a[i]);
	return 0;
}