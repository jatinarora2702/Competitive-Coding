#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, cnt0, cnt1;
	scanf("%d", &n);
	char *s = new char[n+1];
	scanf("%s", s);
	cnt0 = cnt1 = 0;
	for(int i = 0 ; s[i] != '\0' ; i++){
		if(s[i] == '0') cnt0++;
		else if(s[i] == '1') cnt1++;
	}
	printf("%d", abs(cnt0-cnt1));
	return 0;
}