#include <bits/stdc++.h>
#define N 200005
using namespace std;
char a[N], b[N];
int present[30], change[30];
int main() {
	int n, m, temp;
	char x, y;
	scanf("%d%d%s", &n, &m, a);
	// cout << "a=" << a << endl;
	for(int i = 0 ; i < 26 ; i++){
		present[i] = i;
		change[i] = i;
	}
	for(int i = 0 ; i < m ; i++){
		scanf(" %c %c", &x, &y);
		if(x == y)
			continue;
		// cout << "x=" << x << "y=" << y << endl;
		temp = present[x-'a'];
		change[temp] = y-'a';
		present[x-'a'] = y-'a';
		temp = present[y-'a'];
		change[temp] = x-'a';
		present[y-'a'] = x-'a';
	}
	for(int i = 0 ; i < n ; i++){
		b[i] = 'a' + change[a[i]-'a'];
	}
	b[n] = '\0';
	printf("%s\n", b);
	return 0;
}