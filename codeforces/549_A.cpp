#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int m,n, cnt;
	char **a, *s;
	scanf("%d%d", &m, &n);
	a = new char*[m];
	s = new char[5];
	s[4] = '\0';
	for(int i = 0 ; i < m ; i++){
		a[i] = new char[n+1];
		scanf("%s", a[i]);
	}
	cnt = 0;
	for(int i = 0 ; i < m-1 ; i++){
		for(int j = 0 ; j < n-1 ; j++){
			if(a[i][j] != 'f' and a[i][j] != 'a' and a[i][j] != 'c' and a[i][j] != 'e')
				continue;
			s[0] = a[i][j];
			s[1] = a[i][j+1];
			s[2] = a[i+1][j];
			s[3] = a[i+1][j+1];
			sort(s,s+4);
			if(s[0] == 'a' and s[1] == 'c' and s[2] == 'e' and s[3] == 'f')
				cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}