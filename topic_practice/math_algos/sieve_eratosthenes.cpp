#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n, i, j;
	int *a;
	printf("Enter a no. to find all prime no.s below it : ");
	scanf("%d", &n);
	a = new int[n+1];
	i = 2;
	for(int j = 0 ; j <= n ; j++)
		a[j] = true;
	while(i <= n){
		printf("%d	", i);
		for(int j = i ; j <= n ; j += i)
			a[j] = false;
		i++;
		while(i <= n && a[i] == false)
			i++;
	}
	printf("\n");
	return 0;
}