#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 10005

int main() {
	int n, m, cnt, d, i;
	scanf("%d%d", &n, &m);
	switch(n) {
		case 1: 
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: d = 31; break;
		case 2: d = 28; break;
		default: d = 30;
	}
	cnt = 1;
	for(i = 1 ; i < d ; i++) {
		m++;
		if(m > 7) {
			m = 1;
			cnt++;
		}
	}
	printf("%d\n", cnt);
}