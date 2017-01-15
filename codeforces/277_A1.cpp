#include <bits/stdc++.h>
#define PB push_back
#define N 105

using namespace std;

vector < int > v[N], temp, lang[N];
int a[N], b[N];
int main() {
	int n, m, ans, i, j, k, x, y;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &x);
		for(j = 0 ; j < x ; j++) {
			scanf("%d", &y);
			y--;
			v[i].PB(y);
			lang[y].PB(i);
		}
	}
	ans = 0;
	for(i = 0 ; i < m ; i++) {
		if(a[i] == 0 && lang[i].size() > 0) {
			a[i] = 1;
			ans++;
			temp = lang[i];
			for(j = 0 ; j < temp.size() ; j++) {
				if(b[temp[j]] == 0) {
					b[temp[j]] = 1;
					for(k = 0 ; k < v[temp[j]].size() ; k++) {
						if(a[v[temp[j]][k]] == 0) {
							a[v[temp[j]][k]] = 1;
							temp.insert(temp.end(), lang[v[temp[j]][k]].begin(), lang[v[temp[j]][k]].end());
						}
					}
				}
			}
		}
	}
	ans = max(0, ans-1);
	for(i = 0 ; i < n ; i++) {
		if(b[i] == 0) {
			b[i] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}