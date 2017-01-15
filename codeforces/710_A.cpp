#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7LL;
const lli LINF = 1e18 + 7LL;

char s[10];
int main() {
	scanf("%s", s);
	int r, c;
	c = s[0] - 'a';
	r = s[1] - '1';
	if(c == 0 || c == 7) {
		if(r == 0 || r == 7) {
			printf("3\n");
		}
		else {
			printf("5\n");
		}
	}
	else if(r == 0 || r == 7) {
		printf("5\n");
	}
	else {
		printf("8\n");
	}
	return 0;
}