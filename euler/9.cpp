#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	for(a = 1 ; a < 1000 ; a++) {
		for(b = 501-a ; b < 1000 ; b++) {
			if(a*b == 1000*(a+b-500) && a != b && (1000-a-b)>max(a, b)) {
				printf("%d %d %d\n", a, b, 1000-a-b);
				printf("%d\n", a*b*(1000-a-b));
				return 0;
			}
		}
	}
	return 0;
}