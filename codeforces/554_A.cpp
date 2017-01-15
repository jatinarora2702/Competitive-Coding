#include <bits/stdc++.h>
using namespace std;
char s[21];
int main(){
	int n;
	scanf("%s", s);
	n = strlen(s);
	printf("%d", (n+1) * 26 - n);
	return 0;
}