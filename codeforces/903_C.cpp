#include <bits/stdc++.h>
using namespace std;

const int N = 5100;

map < int, int > mp;
map < int, int >::iterator it;
int main() {
	int n, x, i, maxm;
	scanf("%d", &n);
	maxm = 0;
	for (i = 0 ; i < n ; i++) {
		scanf("%d", &x);
		mp[x]++;
		if (mp[x] > maxm) {
			maxm = mp[x];
		}
	}
	printf("%d\n", maxm);
	return 0;
}