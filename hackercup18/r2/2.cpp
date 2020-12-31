#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define N 200005

using namespace std;

typedef long long int lli;

const int INF = 1e9 + 7;

int p[N], dem[N];
lli total;
vector <int> g[N];

int getmax(vector<int> v) {
	int i, m;
	m = 0;
	for(i = 0; i < v.size(); i++) {
		if(v[m] < v[i])
			m = i;
	}
	return m;
}

vector<int> merge(vector<vector<int>> v) {
	int i, m;
	vector<int> vp, vw, vr;
	
	for(i = 0; i < v.size(); i++) {
		vw.PB(v[i][0]);
		vp.PB(0);
	}
	while(true) {
		m = getmax(vw);
		if(vw[m] != -INF) {
			vr.PB(vw[m]);
			vp[m]++;
			vw[m] = (vp[m] < v[m].size()) ? v[m][vp[m]] : -INF;
		}
		else {
			break;
		}
	}
	return vr;
}

vector<int> process(int s) {
	int i, m;
	vector<vector<int>> v;
	
	vector<int> vc;
	vc.PB(s);
	v.PB(vc);
	
	for(i = 0; i < g[s].size(); i++) {
		vector<int> vtemp = process(g[s][i]);
		if(vtemp.size() > 0)
			v.PB(vtemp);
	}
	
	vector<int> vs = merge(v);
	
	cout << "s: " << s << endl;
	cout << "vs: ";
	for(i = 0; i < vs.size(); i++)
		cout << vs[i] << " ";
	cout << endl;

	m = min((int)vs.size(), dem[s]);
	for(i = 0; i < m; i++)
		total += (lli)vs[i];
	
	vector<int> vr;
	for(i = m; i < vs.size(); i++)
		vr.PB(vs[i]);
	
	cout << "vr: ";
	for(i = 0; i < vr.size(); i++)
		cout << vr[i] << " ";
	cout << endl;
	return vr;
}

int main() {
	int t, h, n, m, a, b, i, k;
	cin >> t;
	for(h = 1; h <= t; h++) {
		cin >> n >> m >> a >> b;
		cout << n << " " << m << " " << a << " " << b << endl;
		for(i = 0; i < n; i++)
			g[i].clear();
		p[0] = -1;
		for(i = 1; i < n; i++) {
			cin >> p[i];
			g[p[i]].PB(i);
			dem[i] = 0;
		}
		
		for(i = 0; i < m; i++) {
			k = ((a * i) % n + b) % n;
			dem[k]++;
		}

		for(i = 0; i < n; i++) {
			cout << i << "(" << dem[i] << "): ";
			for(int j = 0; j < g[i].size(); j++) {
				cout << g[i][j] << " ";
			}
			cout << endl;
		}

		total = 0LL;
		process(0);
		cout << "Case #" << h << ": " << total << endl;
	}
	return 0;
}