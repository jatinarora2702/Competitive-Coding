#include <bits/stdc++.h>
#define N 200005
#define M 25

using namespace std;

typedef long long int lli;

int a[M], b[M], u[M], d[M], orig[N];
double h[N], lt[N], rt[N];
int n, m, w, x, y, z;

void init() {
	int i;
	lli tmp;
	for(i = 2; i < n; i++) {
		tmp = (lli)w * (lli)orig[i-2];
		tmp %= (lli)z;
		tmp += (lli)x * (lli)orig[i-1];
		tmp %= (lli)z;
		tmp += (lli)y;
		tmp %= (lli)z;
		orig[i] = tmp;
	}

	for(i = 0; i < n; i++)
		h[i] = orig[i];
}

void handle(int s) {
	int i;
	double diff;
	for(i = 0; i < n; i++)
		lt[i] = rt[i] = 0.0;
	for(i = a[s]-1; i < b[s]-1; i++) {
		if(h[i+1] - h[i] - u[s] > 0.0) {
			diff = (h[i+1] - h[i] - u[s]) / 2.0;
			lt[i] += diff;
			rt[i+1] -= diff;
		}
		else if(h[i] - h[i+1] - d[s] > 0.0) {
			diff = (h[i] - h[i+1] - d[s]) / 2.0;
			lt[i] -= diff;
			rt[i+1] += diff;
		}
	}
	for(i = 1; i < n; i++)
		rt[i] += rt[i-1];
	for(i = n-2; i >= 0; i--)
		lt[i] += lt[i+1];
	
	for(i = 0; i < n; i++)
		cout << "(" << lt[i] << ", " << rt[i] << ") ";
	cout << endl;

	for(i = 0; i < n; i++)
		h[i] += lt[i] + rt[i];
}

int main() {
	int t, ti, i, j;
	double maxm, diff;
	cout.precision(7);

	cin >> t;
	for(ti = 1; ti <= t; ti++) {
		cin >> n >> m;
		cin >> orig[0] >> orig[1] >> w >> x >> y >> z;
		for(j = 0; j < m; j++)
			cin >> a[j] >> b[j] >> u[j] >> d[j];
		init();
		
		for(i = 0; i < n; i++)
			cout << h[i] << " ";
		cout << endl;

		for(j = 0; j < m; j++)
			handle(j);
		
		for(i = 0; i < n; i++)
			cout << h[i] << " ";
		cout << endl;

		maxm = 0.0;
		for(i = 0; i < n; i++) {
			diff = abs(orig[i] - h[i]);
			if(diff > maxm)
				maxm = diff;
		}
		cout << "Case #" << ti << ": " << fixed << maxm << endl;
	}
	return 0;
}