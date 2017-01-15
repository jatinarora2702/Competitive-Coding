#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	printf("Enter a no. to be multiplied with 7 : ");
	scanf("%d", &n);
	printf("Ans : %d\n", (n << 3) - n);
	return 0;
}