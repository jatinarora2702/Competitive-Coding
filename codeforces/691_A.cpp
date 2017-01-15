#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
using namespace std;

typedef long long int lli;

int main() {
	int n, x, cnt, i, f;
	scanf("%d", &n);
	cnt = 0;
	f = 1;
	for(i = 0  ; i < n ; i++) {
		scanf("%d", &x);
		if(x == 0)
			cnt++;
		if(cnt > 1) {
			f = 0;
			break;
		}
	}
	if((cnt != 1 && n > 1) || (cnt != 0 && n == 1))
		f = 0;
	if(f == 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}