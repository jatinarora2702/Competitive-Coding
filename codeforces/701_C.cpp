#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

#define N 100005

using namespace std;

const int INF = 1e9+7;

char s[N];
map < char, int > mp;
map < char, int > :: iterator it;
int main() {
	int n, i, f, l, flag, ans;
	scanf("%d%s", &n, s);
	ans = INF;
	for(i = 0 ; i < n ; i++) {
		mp[s[i]] = -1;
	}
	for(i = 0 ; i < n ; i++) {
		mp[s[i]] = i;
		f = n - 1;
		l = 0;
		flag = 0;
		for(it = mp.begin() ; it != mp.end() ; it++) {
			if(it->SS == -1) {
				flag = 1;
				break;
			}
			if(f > it->SS)
				f = it->SS;
			if(l < it->SS)
				l = it->SS;
		}
		if(flag == 0) {
			ans = min(ans, l - f + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}