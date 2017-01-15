#include <iostream>
#include <cstdio>
using namespace std;
double sqrtt(int n){
	double x, y, e;
	x = n - 0.5;
	y = 1;
	e = 0.000000001;
	while(x - y > e){
		x = (x + y) / 2;
		y = n / x;
	}
	return x;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%.16lf\n", sqrtt(n));
	return 0;
}