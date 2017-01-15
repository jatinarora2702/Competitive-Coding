#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

int main() {
	int t, n, cnt[4], i;
	char a[100];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", a);
		for(i = 0 ; i < 4 ; i++)
			cnt[i] = 0;
		for(i = 0 ; a[i] != '\0' ; i++) {
			if(a[i] == 'R')
				cnt[0]++;
			else if(a[i] == 'G')
				cnt[1]++;
			else if(a[i] == 'B')
				cnt[2]++;
			else if(a[i] == 'W')
				cnt[3]++;
		}
		// cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
		if((cnt[0] % 2 == 0) && (cnt[1] % 2 == 0) && (cnt[2] % 2 == 0) && (cnt[3] % 2 == 0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}