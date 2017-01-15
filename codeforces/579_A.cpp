#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, cnt;
	scanf("%d", &x);
	cnt = 0;
	while(x != 0){
		if(x % 2 == 1){
			cnt++;
			x--;
		}
		else
			x = x / 2;
	}
	printf("%d", cnt);
	return 0;
}