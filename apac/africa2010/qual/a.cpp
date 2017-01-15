#include <bits/stdc++.h>
#define PB push_back
#define N 2005

using namespace std;

int a[N];
map < int, vector < int > > mp;
int main() {
	int t, c, n, i, x, y, h;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &c, &n);
		mp.clear();
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
			mp[a[i]].PB(i);
		}
		for(i = 0 ; i < n ; i++) {
			if(c-a[i] > 0) {
				if(c-a[i] == a[i] && mp[a[i]].size() > 1) {
					x = mp[a[i]][0];
					y = mp[a[i]][1];
					// printf("h=%d | x= %d | y= %d | 1\n", h, x, y);
					break;
				}
				else if(c-a[i] != a[i] && mp[c-a[i]].size() > 0) {
					x = i;
					y = mp[c-a[i]][0];
					// printf("h=%d | x= %d | y= %d | 2\n", h, x, y);
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n", h, x+1, y+1);
	}
	return 0;
}