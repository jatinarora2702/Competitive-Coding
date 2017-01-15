#include <bits/stdc++.h>
#define N 55
using namespace std;
int a[N];
char s[20];
int main() {
	int t, n, i, f, ke, ko, ch, win, waste;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %s", &n, s);
		ke = ko = 0;
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		if(strcmp(s, "Dee") == 0){
			f = 0;
		}
		else{
			f = 1;
		}
		if(n == 1 && a[0] % 2 == 0 && f == 0)
			win = 0;
		else
			win = 1;
		if(win == 0) {
			printf("Dee\n");
		}
		else {
			printf("Dum\n");
		}
	}
	return 0;
}