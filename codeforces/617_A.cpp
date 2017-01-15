#include <bits/stdc++.h>
#define N 
using namespace std;
int main(){
	int x, cnt;
	scanf("%d", &x);
	cnt = x / 5;
	x = x % 5;
	if(x != 0)
		cnt++;
	printf("%d", cnt);
	return 0;
}