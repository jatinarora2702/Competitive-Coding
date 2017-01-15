#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	int temp;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main(){
	int t, x1, x2, y1, y2, y, x, g, d;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		y = abs(y2 - y1);
		x = abs(x2 - x1);
		if(x == 0)
			printf("0\n");
		else if(y == 0)
			printf("0\n");
		else {
			g = gcd(x, y);
			x /= g;
			y /= g;
			d = x + y - 1;
			printf("%d\n", g * d);
		}
	}
	return 0;
}