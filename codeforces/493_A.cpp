#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;
map < int, pair < int, int > > mp1, mp2;
char ht[30], at[30];
int main() {
	int n, t, pn;
	char tm, cd;
	scanf("%s %s", ht, at);
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d %c %d %c", &t, &tm, &pn, &cd);
		if(tm == 'a' && mp2[pn].FF < 2){
			(mp2[pn].FF)++;
			if(cd == 'r')
				mp2[pn].FF = 2;
			if(mp2[pn].FF == 2)
				printf("%s %d %d\n", at, pn, t);
		}
		else if(tm == 'h' && mp1[pn].FF < 2){
			(mp1[pn].FF)++;
			if(cd == 'r')
				mp1[pn].FF = 2;
			if(mp1[pn].FF == 2)
				printf("%s %d %d\n", ht, pn, t);
		}
	}
	return 0;
}