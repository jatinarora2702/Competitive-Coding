#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

#define N 200005

int a[N];
int main() {
	int n, i, x, y, f;
	string s;
	scanf("%d", &n);
	cin >> s;
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	i = 0;
	f = INF;
	while(i < n) {
		while(i < n && s[i] == 'L')
			i++;
		if(i == n)
			break;
		x = a[i];
		i++;
		while(i < n && s[i] == 'R') {
			x = a[i];
			i++;
		}
		if(i == n)
			break;
		y = a[i];
		f = min(f, (y-x)/2);
	}
	if(f == INF) 
		printf("-1\n");
	else
		printf("%d\n", f);
	return 0;
}