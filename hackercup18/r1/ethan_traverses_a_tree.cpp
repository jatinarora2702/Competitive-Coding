#include <bits/stdc++.h>
#define N 2005

using namespace std;

int a[N], b[N], c[N], l[N];
vector < int > pre, post;

void findpre(int s) {
	int i;
	pre.push_back(s);
	i = a[s] - 1;
	if(i >= 0)
		findpre(i);
	i = b[s] - 1;
	if(i >= 0)
		findpre(i);
}

void findpost(int s) {
	int i;
	i = a[s] - 1;
	if(i >= 0)
		findpost(i);
	i = b[s] - 1;
	if(i >= 0)
		findpost(i);
	post.push_back(s);
}

int head(int s) {
	if(c[s] == -1)
		return s;
	return head(c[s]);
}

int main() {
	int t, h, n, k, i, j, m1, m2;
	cin >> t;
	for(h = 1; h <= t; h++) {
		cin >> n >> k;
		for(i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		pre.clear();
		post.clear();
		findpre(0);
		findpost(0);
		for(i = 0; i < n; i++)
			c[i] = -1;
		for(i = 0; i < n; i++) {
			m1 = head(pre[i]);
			m2 = head(post[i]);
			if(m1 != m2)
				c[m2] = m1;
		}
		j = 0;
		for(i = 0; i < n; i++) {
			if(c[i] == -1) {
				j = min(j+1, k);
				l[i] = j;
			}
		}
		for(i = 0; i < n; i++) {
			if(c[i] != -1) {
				l[i] = l[head(i)];
			}
		}
		if(j < k)
			cout << "Case #" << h << ": Impossible" << endl;
		else
		{
			cout << "Case #" << h << ": ";
			for(i = 0; i < n; i++)
				cout << l[i] << " ";
			cout << endl;
		}
	}
	return 0;
}