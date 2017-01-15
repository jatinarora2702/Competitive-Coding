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
			if(a[i] == 1)
				waste++;
			if(a[i] % 2 == 0)
				ke++;
			else
				ko++;
		}
		if(strcmp(s, "Dee") == 0){
			f = 0;
		}
		else{
			f = 1;
		}
		ch = f;
		win = -1;
		while(1) {
			if(ch == 1) {
				if(ke > 0) {
					ke--;
					ko++;
					waste++;
				}
				else if(ko > waste) {
					ko--;
				}
				else if(waste > 0) {
					waste--;
					ko--;
				}
				else if(ko == 0) {
					win = 0;
					break;
				}
			}
			else {
				if(ke > 0) {
					ke--;
				}
				else if(ke == 0) {
					win = 1;
					break;
				}
			}
			ch ^= 1;
		}
		if(win == 0) {
			printf("Dee\n");
		}
		else {
			printf("Dum\n");
		}
	}
	return 0;
}