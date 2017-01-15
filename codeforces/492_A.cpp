#include <bits/stdc++.h>
#define N 10000
using namespace std;
int main(){
	int n, x, s, y;
	scanf("%d", &n);
	s = 1;
	x = 1;
	y = 1;
	while(s <= n){
		y++;
		x += y;
		s += x;
	}
	printf("%d\n", y-1);
	return 0;
}