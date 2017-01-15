#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 1000

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

map < char, int > mp;
char smax[N], s[N];
int main() {
	int t, n, h, i, j, maxm, cnt;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		maxm = -1;
		scanf("%d ", &n);
		for(i = 0 ; i < n ; i++) {
			fgets(s, N, stdin);
			cnt = 0;
			mp.clear();
			for(j = 0 ; s[j] != '\0' ; j++) {
				if(s[j] >= 'A' && s[j] <= 'Z') {
					if(mp[s[j]] == 0) {
						cnt++;
						mp[s[j]]++;
					}
				}
			}
			if(cnt > maxm) {
				maxm = cnt;
				strcpy(smax, s);
			}
			else if(cnt == maxm) {
				if(strcmp(smax, s) > 0) {
					strcpy(smax, s);
				}
			}
		}
		cout << "Case #" << h << ": " << smax;
	}
	return 0;
}