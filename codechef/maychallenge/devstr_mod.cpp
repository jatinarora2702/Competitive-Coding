#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int t, n, k, c, pos, f;
	char *s, ch, *a;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		s = new char[n+1];
		a = new char[n+1];
		scanf("%s", s);
		if(k == 1){
			int i = 0;
			ch = '0';
			f = 0;
			for(int i = 0 ; i < n ; i++ ) {
				a[i] = s[i];
			}
			a[i] = '\0';
			while(i < n){
				if(ch != s[i])
					f++;
				a[i] = ch;
				ch = (ch == '0') ? '1' : '0';
				i++;
			}
			int min = f;
			i = 0;
			ch = '1';
			f = 0;
			while(i < n){
				if(ch != s[i])
					f++;
				s[i] = ch;
				ch = (ch == '0') ? '1' : '0';
				i++;
			}
			if(min < f)
				printf("%d\n%s\n", min, a);
			else
				printf("%d\n%s\n", f, s);
			continue;
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
					if(i+1 < n and s[i+1] == s[i]){
						c = 1;
						pos = i;
						s[pos] = (s[pos] == '1') ? '0' : '1';
						ch = s[i];
					}
					else if(s[i+1] != s[i]){
						c = c - (k+1) / 2;
						pos = pos + (k+1) / 2;
						s[pos] = (s[pos] == '1') ? '0' : '1';	
						if(pos == i)
							ch = s[i];
					}
				}
				continue;
			}
			if(s[i] != ch){
				c = 1;
				ch = s[i];
				pos = i;
			}
		}
		printf("%d\n%s\n", f, s);
	}
	return 0;
}