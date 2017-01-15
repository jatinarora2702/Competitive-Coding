#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n, x1, x2, y1, y2, s, p;
	scanf("%d", &n);
	s = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		p = (x2-x1+1) * (y2-y1+1);
		s += p;
	}
	printf("%d", s);
	return 0;
}