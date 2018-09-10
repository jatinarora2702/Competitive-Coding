#include <bits/stdc++.h>
using namespace std;

map < int, int > mp;
vector < int > v;
int main() {
	int t, a, b, f, x, i;
	scanf("%d", &t);
	a = 0;
	while (a <= 100) {
		mp[a] = 1;
		a += 3;
	}
	b = 0;
	while (b <= 100) {
		v.push_back(b);
		b += 7;
	}
	while (t--) {
		scanf("%d", &x);
		f = 0;
		for(i = 0; i < v.size(); i++) {
			if (mp[x - v[i]] == 1) {
				printf("YES\n");
				f = 1;
				break;
			}
		}
		if (f == 0)
			printf("NO\n");
	}
	return 0;
}