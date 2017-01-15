#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 100005
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

pii p[N];
int x, y, n;
const lli INF = 1e18;

int getslp(int id1, int id2, int i){
	lli t1, t2, t3, t4, d1, d2;
	t1 = (lli)p[id1].FF - (lli)p[i].FF;
	t2 = (lli)p[id1].SS - (lli)p[i].SS;
	t3 = (lli)p[id1].FF - (lli)p[i].FF;
	t4 = (lli)p[id1].SS - (lli)p[i].SS;
	d1 = t1 * t3;
	d2 = t4 * t2;
	if(d1 == 0){
		if(d2 > 0)
			return 1;
		else
			return 0;
	}
	if(d2 == 0){
		if(d1 > 0)
			return 1;
		else
			return 0;
	}
	if(d1 > 0 && d2 < 0)
		return 0;
	if(d1 < 0 && d2 > 0)
		return 0;
	return 1;
}

lli area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs(((lli)x1*(lli)(y2-y3) + (lli)x2*(lli)(y3-y1)+ (lli)x3*(lli)(y1-y2)));
}

lli istr(int z){
	return area(p[x].FF, p[x].SS, p[y].FF, p[y].SS, p[z].FF, p[z].SS);
}

void findpts(){
	x = 0;
	y = 1;
	int st;
	for(int i = 2 ; i < n ; i++){
		if(istr(i) == 0){
			st = getslp(x, y, i);
			if(st == 0){
				y = i;
			}
		}
	}
}

int main(){
	int i, ans;
	lli minm, val;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++){
		scanf("%d%d", &p[i].FF, &p[i].SS);
	}
	findpts();

	minm = INF;
	for(i = 0 ; i < n ; i++){
		if(i == x || i == y)
			continue;
		val = istr(i);
		if(val > 0LL){
			if(val < minm){
				ans = i;
				minm = val;
			}
		}
	}
	printf("%d %d %d\n", x+1, y+1, ans+1);
	return 0;
}