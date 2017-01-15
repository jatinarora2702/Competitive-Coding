#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long int lli;
char a[N], b[N];
int c1[N];
int main() {
	int cnt, n, m;
	lli s;
	scanf("%s%s", a, b);
	for(m = 0 ; a[m] != '\0' ; m++);
	for(n = 0 ; b[n] != '\0' ; n++);
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(b[i] == '1')
			cnt++;
		c1[i] = cnt;
	}
	s = 0;
	for(int i = 0 ; i < m ; i++){
		cnt = c1[n-m+i];
		if(i > 0)
			cnt -= c1[i-1];
		if(a[i] == '0')
			s += (lli)cnt;
		else
			s += (lli)((n-m+1) - cnt);
	}
	cout << s;
	return 0;
}