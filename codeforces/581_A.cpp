#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, cnt;
	scanf("%d%d", &a, &b);
	cnt = min(a, b);
	a -= cnt;
	b -= cnt;
	a = a/2;
	b = b/2;
	printf("%d %d", cnt, (a+b));
	return 0;
}