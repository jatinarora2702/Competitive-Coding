#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

char s[N];
int main() {
	int i, f, n;
	scanf("%s", s);
	f = 0;
	n = strlen(s);
	for(i = 0 ; s[i] != '\0' ; i++) {
		if(f == 0 && s[i] != 'a') {
			f = 1;
			s[i]--;
		}
		else if(f == 1) {
			if(s[i] == 'a') {
				f = 3;
				break;
			}
			else {
				s[i]--;
			}
		}
	}
	if(f == 0) {
		if(s[n-1] == 'a')
			s[n-1] = 'z';
		else
			s[n-1]--;
	}
	printf("%s\n", s);
	return 0;
}