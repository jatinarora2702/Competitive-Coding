#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int a[N], d[N], n, m;
set < int > st;

bool solve(int s) {
	int i, j, k;
	st.clear();
	k = 0;
	for(i = s-1 ; i >= 0 ; i--) {
		j = d[i];
		if(j > 0 && st.find(j) == st.end() && (k + a[j-1]) <= i) {
			st.insert(j);
			k += a[j-1];
		}
		else {
			k = max(0, k-1);
		}
	}
	return (k == 0 && st.size() == m);
}

int main() {
	int l, u, t, i;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	for(i = 0 ; i < m ; i++)
		scanf("%d", &a[i]);
	l = 0;
	u = n;
	while(l <= u) {
		t = (l + u) / 2;
		if(solve(t))
			u = t-1;
		else
			l = t+1;
	}
	if(u < n && solve(u+1))
		printf("%d\n", u+1);
	else
		printf("-1\n");
	return 0;
}