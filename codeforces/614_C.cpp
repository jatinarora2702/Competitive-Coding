#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1000005
#define INF 1000000007
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
typedef long double ld;
const int MOD = 1e9+7;
ld pi = 4.0 * atan(1.0);
stack < int > stk;
pii poly[N], p;
int main(){
	int n, x, y, k, rem, j;
	lli minm, maxm, d, ansi;
	ld ans;
	scanf("%d%d%d", &n, &p.FF, &p.SS);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &poly[i].FF, &poly[i].SS);
	}
	for(int i = 0 ; i < n;  i++){
		x = abs(p.FF - poly[i].FF);
		y = abs(p.SS - poly[i].SS);
		d = (lli)x * (lli)x + (lli)y * (lli)y;
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
		d = (lli)x1 * (lli)y2 - (lli)x2 * (lli)y1 + (lli)x2 * (lli)y3 - (lli)x3 * (lli)y1 + (lli)x3 * (lli)y1 - (lli)x1 * (lli)y3;
		d = abs(d);
		dist = (lli)(x2 - x1) * (lli)(x2 - x1) + (lli)(y2 - y1) * (lli)(y2 - y1);
		dist = abs(dist);
		fdist = sqrt(dist);
		fdist *= (ld)2.0;
		fd = (ld)d / fdist;
		fd *= fd;
		if(fd > maxm){
			maxm = fd;
		}
		if(fd < minm){
			minm = fd;
		}
	}
	pi *= 10000000;
	ansi = abs(maxm - minm);
	ansi *= (lli)(pi);
	j = 0;
	while(j < 7){
		rem = ansi % 10;
		ansi /= 10;
		stk.push(rem);
		j++;
	}
	cout << ansi << ".";
	while(!stk.empty()){
		k = stk.top();
		cout << k;
		stk.pop();
	}
	return 0;
}