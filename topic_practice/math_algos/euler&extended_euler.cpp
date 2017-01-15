// GEEKS FOR GEEKS

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int euler(int a, int b){
	if(a == 0)
		return b;
	return euler(b%a, a);
}
int extended_euler(int a, int b, int &x, int &y){
	if(a == 0) {
		x = 0, y = 1;
		return b;
	}
	int x1, y1, d;
	d = extended_euler(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}
int main(){
	int a, b, x, y, d;
	printf("Euler : (finding gcd) : Enter no.s a and b : \n");
	scanf("%d%d", &a, &b);
	printf("GCD(%d, %d) : %d\n\n", a, b, euler(a, b));
	printf("Extended Euler : ax + by = gcd(a, b) :\n");
	d = extended_euler(a, b, x, y);
	printf("a : %d | x : %d | b : %d | y : %d | gcd : %d\n", a, x, b, y, d);
	return 0;
}