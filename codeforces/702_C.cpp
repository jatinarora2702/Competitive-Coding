#include <bits/stdc++.h>
#define N 100005

using namespace std;

const int INF = INT_MAX;

int a[N], b[N], c[N];
set < int > s;
set < int > :: iterator it;
int main() {
	int n, m, i, j, maxm;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		c[i] = INF;
		s.insert(a[i]);
	}
	i = 0;
	for(it = s.begin() ; it != s.end() ; it++) {
		a[i++] = *it;
	}
	n = i;
	s.clear();
	for(i = 0 ; i < m ; i++) {
		scanf("%d", &b[i]);
		s.insert(b[i]);
	}
	i = 0;
	for(it = s.begin() ; it != s.end() ; it++) {
		b[i++] = *it;
	}
	m = i;
	j = 0;
	i = 0;
	while(i < n) {
		c[i] = min(c[i], abs(a[i] - b[j]));
		if(j-1 >= 0) c[i] = min(c[i], abs(a[i] - b[j-1]));
		if(j+1 < m) c[i] = min(c[i], abs(a[i] - b[j+1]));
		// printf("i=%d | j=%d | val=%d | c=%d\n", i, j, abs(a[i] - b[j]), c[i]);
		if(a[i] <= b[j])
			i++;
		else {
			if(j < m-1)
				j++;
			else
				i++;
		}
	}
	maxm = 0;
	for(i = 0 ; i < n ; i++) {
		maxm = max(c[i], maxm);
	}
	printf("%d\n", maxm);
}