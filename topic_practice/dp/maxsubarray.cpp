#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
int main() {
	int n, *a, max, cnt_max;
	printf("Enter the no. of elements in the array : ");
	scanf("%d", &n);
	a = new int[n];
	max = -INF;
	printf("Enter the array :\n");
	for(int i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		if(max < a[i])
			max = a[i];
	}
	if(max < 0)
		printf("Max. sum is : %d\n", max);
	else{
		cnt_max = 0;
		for(int i = 0 ; i < n ; i++) {
			cnt_max = cnt_max + a[i];
			if(cnt_max < 0)
				cnt_max = 0;
			else if(max < cnt_max)
				max = cnt_max;
		}
		printf("Max. sum is : %d\n", max);
	}
	return 0;
}