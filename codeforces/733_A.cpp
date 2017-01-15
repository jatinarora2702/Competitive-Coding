#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005

int main() {
	int i, prev, maxm;
	string s;
	cin >> s;
	prev = -1;
	maxm = 0;
	for(i = 0 ; i < s.length() ; i++) {
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
			maxm = max(maxm, i - prev);
			prev = i;
		}
	}
	maxm = max(maxm, (int)s.length() - prev);
	printf("%d\n", maxm);
	return 0;
}