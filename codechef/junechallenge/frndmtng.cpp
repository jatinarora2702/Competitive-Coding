#include <iostream>
#include <stdio.h>
#include <cmath>
#define MIN 1e-6
using namespace std;
int main(){
	int t, T1, T2, t1, t2;
	double p1, p2, x, x1, tt1, tt2, min;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &T1, &T2, &t1, &t2);
		min = (T1 < T2) ? T1 : T2;
		if(min == T1){
			x2 = T2 - (T1+t1);
			if(x2 < 0) x2 = 0;
			p2 = x2 / T2;
		}
		else if(min == T2){
			x1 = T1 - (T2+t2);
			if(x1 < 0) x1 = 0;
			p1  = x1 / T1;
		}
		tt1 = t1;
		tt2 = t2;
		if(t1 == 0) tt1 = MIN;
		if(t2 == 0) tt2 = MIN;
		x1 = (double)T2 - tt1;
		if(x1 < 0)
			x1 = 0;
		p1 = x1 / (double)T1;
		p2 = tt1 / (double)T2;
		printf("%lf\n", 1 - p1*p2);
	}
	return 0;
}