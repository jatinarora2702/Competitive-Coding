#include <iostream>
#include <stdio.h>
#define N 11
using namespace std;
int main() {
	int t, i, j, n, f;
	char *s = new char[N];
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		for(n = 0 ; s[n] != '\0' ; n++);
		i = 0;
		j = n-1;
		f = 1;
		while(i < j){
			if(s[i] != s[j]){
				f = 0;
				break;
			}
			i++;
			j--;
		}
		if(f == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}