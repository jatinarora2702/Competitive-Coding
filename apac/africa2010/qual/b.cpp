#include <bits/stdc++.h>
#define N 1005
using namespace std;

char s[N], *s1[N];
int main() {
	int n, i, j, k;
	scanf("%d\n", &n);
	for(i = 0 ; i < n ; i++) {
		fgets(s, N, stdin);
		s[strlen(s)-1] = '\0';
		j = 0;
		s1[j] = strtok(s, " ");
		while(1) {
			j++;
			s1[j] = strtok(NULL, " ");
			if(s1[j] == NULL)
				break;
		}
		printf("Case #%d: ", i+1);
		for(k = j-1 ; k > 0 ; k--) {
			printf("%s ", s1[k]);
		}
		printf("%s\n", s1[k]);
	}
	return 0;
}