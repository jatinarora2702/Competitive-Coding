#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 1005

map < string, int > mp;

int gethead(int s) {
	if(a[s] == -1)
		return s;
	a[s] = gethead(a[s]);
	return a[s];
}

int getstatus(int u, int v) {
	int uarr[2], varr[2];
	uarr[0] = gethead(rel[u][0]);
	varr[0] = gethead(rel[v][0]);
	uarr[1] = gethead(rel[u][1]);
	varr[1] = gethead(rel[v][1]);
	if(uarr[0] == varr[0])
		return 1;
	if(uarr[1] == varr[1])
		return 2;
	return 3;
}

void update(int u, int v, int f) {
	if(f == 1) {
		
	}
}

int main() {
	string s1, s2;
	int n, m, q, i, c, u, v, f, k;
	cin >> n >> m >> q;
	c = 0;
	mp.clear();
	vrel.clear();
	vq.clear();
	for(i = 0 ; i < n ; i++) {
		cin >> s1;
		mp[s1] = c++;
	}
	for(i = 0 ; i < m ; i++) {
		cin >> k >> s1 >> s2;
		u = mp[s1];
		v = mp[s2];
		f = getstatus(u, v);
		if(f == 3) {
			update(u, v, k);
			f = k;
		}
		vrel.PB((f == k) ? 1 : 0);
	}
	for(i = 0 ; i < q ; i++) {
		cin >> s1 >> s2;
		u = mp[s1];
		v = mp[s2];
		f = getstatus(u, v);
		vq.PB(f);
	}
	for(i = 0 ; i < vrel.size() ; i++) {
		if(vrel[i] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	for(i = 0 ; i < vq.size() ; i++)
		printf("%d\n", vq[i]);
	return 0;
}