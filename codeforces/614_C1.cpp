#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1000005
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
typedef long double ld;
ld pi = 4.0 * atan(1.0);
pii poly[N], p;
int main(){
	int n, x1, y1, x2, y2, x3, y3;
	ld minm, maxm, d, ans, area;
	lli t;
	cout.precision(18);
	scanf("%d%d%d", &n, &p.FF, &p.SS);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &poly[i].FF, &poly[i].SS);
	}
	for(int i = 0 ; i < n;  i++){
		x1 = abs(p.FF - poly[i].FF);
		y1 = abs(p.SS - poly[i].SS);
		t = (lli)x1 * (lli)x1 + (lli)y1 * (lli)y1;
		d = sqrt(t);
		cout << fixed << "d=" << d << endl;
		if(i == 0 || d > maxm){
			maxm = d;
		}
		if(i == 0 || d < minm){
			minm = d;
		}
	}
	for(int i = 0 ; i < n-1 ; i++){
		x1 = poly[i].FF;
		y1 = poly[i].SS;
		x2 = poly[i+1].FF;
		y2 = poly[i+1].SS;
		x3 = p.FF;
		y3 = p.SS;
		t = (lli)x1 * (lli)y2 - (lli)x2 * (lli)y1 + (lli)x2 * (lli)y3 - (lli)x3 * (lli)y1 + (lli)x3 * (lli)y1 - (lli)x1 * (lli)y3;
		t = abs(t);
		area = t / 2.0;
		t = (lli)(x2 - x1) * (lli)(x2 - x1) + (lli)(y2 - y1) * (lli)(y2 - y1);
		t = abs(t);
		d = sqrt(t);
		d = area / d;
		cout << "di=" << fixed << d << endl;
		if(d > maxm){
			maxm = d;
		}
		if(d < minm){
			minm = d;
		}
	}
	x1 = poly[0].FF;
	y1 = poly[0].SS;
	x2 = poly[n-1].FF;
	y2 = poly[n-1].SS;
	x3 = p.FF;
	y3 = p.SS;
	t = (lli)x1 * (lli)y2 - (lli)x2 * (lli)y1 + (lli)x2 * (lli)y3 - (lli)x3 * (lli)y1 + (lli)x3 * (lli)y1 - (lli)x1 * (lli)y3;
	t = abs(t);
	area = t / 2.0;
	t = (lli)(x2 - x1) * (lli)(x2 - x1) + (lli)(y2 - y1) * (lli)(y2 - y1);
	t = abs(t);
	d = sqrt(t);
	d = area / d;
	cout << "di=" << fixed << d << endl;
	if(d > maxm){
		maxm = d;
	}
	if(d < minm){
		minm = d;
	}
	maxm *= maxm;
	minm *= minm;
	cout << "maxm=" << fixed << maxm << " minm=" << fixed << minm << endl;
	ans = abs(maxm - minm);
	ans *= pi;
	cout << fixed << ans;
	return 0;
}