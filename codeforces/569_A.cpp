#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, s, q, c, d;
	c = 0;
	scanf("%d%d%d", &t, &s, &q);
	while(s < t){
		c++;
		s = s * q;
	}
	printf("%d\n", c);
	return 0;
}