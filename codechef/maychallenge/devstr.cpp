#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, n, k, c, pos, f, min;
	char *s, ch, *cs;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		s = new char[n+1];
		cs = new char[n+1];
		scanf("%s", s);
		for(int i = 0 ; i < n ; i++ ) {
			cs[i] = s[i];
		}
		c = 1;
		ch = s[0];
		pos = 0;
		f = 0;
		for(int i = 1 ; i < n ; i++ ) {
			if(s[i] == ch){
				c++;
				if(c == k+1){
					f++;
					c = 1;
					pos = i;
					s[pos] = (s[pos] == '1') ? '0' : '1';
					ch = s[i];
				}
				continue;
			}
			if(s[i] != ch){
				c = 1;
				ch = s[i];
				pos = i;
			}
		}
		min = f;

		c = 1;
		ch = cs[0];
		pos = 0;
		f = 0;
		for(int i = 1 ; i < n ; i++ ) {
			if(cs[i] == ch){
				c++;
				if(c == k+1){
					f++;
					c = c - (k+1) / 2;
					pos = pos + (k+1) / 2;
					cs[pos] = (cs[pos] == '1') ? '0' : '1';
					if(pos == i)
						ch = cs[i];
				}
				continue;
			}
			if(cs[i] != ch){
				c = 1;
				ch = cs[i];
				pos = i;
			}
		}
		if(f < min)
			printf("%d\n%s\n", f, cs);
		else
			printf("%d\n%s\n", min, s);
	}
	return 0;
}