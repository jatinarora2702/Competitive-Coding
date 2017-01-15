#include <bits/stdc++.h>
#define N 100005
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int(i) = (a) ; (i) < (b) ; (i)++)
#define repn(i, a, b) for(int(i) = (a) ; (i) >= (b) ; (i)--)
#define sc(a) scanf("%d", &(a))
#define sc2(a, b) scanf("%d%d", &(a), &(b))
#define pr(a) printf("%d ", (a))
#define pr2(a, b) printf("(%d %d) ", (a), (b))
#define prn2(a, b) printf("%d %d\n", (a), (b))
#define prn(a) printf("%d\n", (a))

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int MOD = 1e9+7;
const int INF = 1e9+7;
const lli INFL = 1e18+7;

ld getdist(pii a, pii b){
	return sqrt(((lli)(a.FF - b.FF) * (lli)(a.FF - b.FF)) + ((lli)(a.SS - b.SS) * (lli)(a.SS - b.SS)));
}

lli area(int x1, int y1, int x2, int y2, int x3, int y3){
	return abs((lli)x1 * (lli)(y2 - y1) + (lli)x2 * (lli)(y3 - y2) + (lli)x3 * (lli)(y1 - y3));
}

int isvalid(pii p1, pii p2, pii p3){
	if((lli)(p2.SS - p1.SS) * (lli)(p3.FF - p1.FF) == (lli)(p3.SS - p1.SS) * (lli)(p2.FF - p1.FF))
		return 0;
	return 1;
	// if(area(p1.FF, p1.SS, p2.FF, p2.SS, p3.FF, p3.SS) > 0){
	// 	cout << "area:" << area(p1.FF, p1.SS, p2.FF, p2.SS, p3.FF, p3.SS) << endl;
	// 	return 1;
	// }
	// else
	// 	return 0;
}

pii p[N];
pair < ld, int > a[N];
int main(){
	int n, x, y, z;
	sc(n);
	rep(i, 0, n){
		sc2(p[i].FF, p[i].SS);
	}
	rep(i, 0, n){
		a[i].FF = getdist(p[0], p[i]);
		a[i].SS = i;
	}
	sort(a, a+n);
	// rep(i, 0, n)
	// 	printf("(%LF, %d)\n", a[i].FF, a[i].SS);
	x = a[0].SS;
	y = a[1].SS;
	// cout << "y=" << y << endl;
	rep(i, 2, n){
		z = a[i].SS;
		if(isvalid(p[x], p[y], p[z])){
			break;
		}
	}
	printf("%d %d %d\n", x+1, y+1, z+1);
	return 0;
}