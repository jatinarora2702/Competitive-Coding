#include <bits/stdc++.h>
using namespace std;
#define N 105

char s[N];
vector < int > v;
int main() {
	int n, i, f, cnt, gcnt;
	scanf("%d%s", &n, s);
	f = 0;
	cnt = 0;
	gcnt = 0;
	for(i = 0 ; i <= n ; i++) {
		if(s[i] == 'B' && f == 0) {
			f = 1;
			cnt++;
			gcnt++;
		}
		else if(s[i] == 'B' && f == 1) {
			cnt++;
		}
		else if(s[i] != 'B' && f == 1) {
			v.push_back(cnt);
			cnt = 0;
			f = 0;
		}
	}
	printf("%d\n", gcnt);
	f = 0;
	for(i = 0 ; i < v.size() ; i++) {
		f = 1;
		printf("%d ", v[i]);
	}
	if(f == 1)
		printf("\n");
	return 0;
}