#include <bits/stdc++.h>
#define PB push_back
#define N 105

using namespace std;

vector < string > v;
int a[N];

int main() {
	string str;
	int n, k, i, cnt, cntmax, t, tmax, m;
	scanf("%d%d", &n, &k);
	for(i = 0 ; i < n ; i++) {
		cin >> str;
		v.PB(str);
	}
	for(i = 0 ; i < N ; i++) {
		a[i] = 0;
	}
	for(i = 0 ; i < v.size() ; i++) {
		a[v[i].size()]++;
	}
	cin >> str;
	m = str.size();
	cnt = 0;
	cntmax = 0;
	for(i = 0 ; i < m ; i++) {
		cnt += a[i];
		cntmax += a[i];
	}
	cntmax += a[m];
	cntmax--;
	t = cnt;
	t += 5 * (cnt / k);
	tmax = cntmax;
	tmax += 5 * (cntmax / k);
	t++;
	tmax++;
	printf("%d %d\n", t, tmax);
	return 0;
}