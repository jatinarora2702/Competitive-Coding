#include <bits/stdc++.h>
#define N 100005
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define INF 1000000007
using namespace std;
typedef long long int lli;
pair < pair < int, int > , pair < int, int > > hor[N], ver[N];
bool fn1(pair < pair < int, int > , pair < int, int > > p1, pair < pair < int , int > , pair < int, int > > p2){
	if(p1.FF.FF == p2.FF.FF){
		return p1.FF.SS < p2.FF.SS;
	}
	else
		return p1.FF.FF < p2.FF.FF;
}
bool fn2(pair < pair < int, int > , pair < int, int > > p1, pair < pair < int , int > , pair < int, int > > p2){
	if(p1.FF.SS == p2.FF.SS){
		return p1.FF.FF < p2.FF.FF;
	}
	else
		return p1.FF.SS < p2.FF.SS;
}
int main(){
	int n, h, v, x1, x2, y1, y2, q1, q2, qcnt;
	lli cnt;
	scanf("%d", &n);
	h = v = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2){
			ver[v].FF.FF = x1;
			ver[v].FF.SS = y1;
			ver[v].SS.FF = x2;
			ver[v].SS.SS = y2;
			v++;
		}
		else{
			hor[h].FF.FF = x1;
			hor[h].FF.SS = y1;
			hor[h].SS.FF = x2;
			hor[h].SS.SS = y2;
			h++;
		}
	}
	sort(ver, ver+v, fn1);
	sort(hor, hor+h, fn2);
	x1 = -INF;
	y1 = -INF;
	cnt = 0;
	qcnt = 0;
	for(int i = 0 ; i < h ; i++){
		if(y1 == hor[i].FF.SS){
			if(x1 < hor[i].FF.FF){
				x1 = hor[i].SS.FF;
				cnt += (lli)(hor[i].SS.FF - hor[i].FF.FF + 1);
				qq.MP(MP(), MP());
				q1 = lower_bound(ver, ver+v, qq) - ver;
				qq.MP(MP(), MP());
				q2 = upper_bound(ver, ver+v, qq) - ver;
				for(int j = q1 ; j < q2 ; j++){
					if(y1 >= ver[j].FF.SS && y1 <= ver[j].SS.SS)
						qcnt++;
				}
			}
			else{
				if(x1 < hor[i].SS.FF){
					cnt += (lli)(hor[i].SS.FF - x1);
					qq.MP(MP(), MP());
					q1 = lower_bound(ver, ver+v, qq) - ver;
					qq.MP(MP(), MP());
					q2 = upper_bound(ver, ver+v, qq) - ver;
					for(int j = q1 ; j < q2 ; j++){
						if(y1 >= ver[j].FF.SS && y1 <= ver[j].SS.SS)
							qcnt++;
					}
					x1 = hor[i].SS.FF;
				}
			}
		}
		else{
			y1 = hor[i].FF.SS;
			x1 = hor[i].SS.FF;
			cnt += (lli)(hor[i].SS.FF - hor[i].FF.FF + 1);
			qq.MP(MP(), MP());
			q1 = lower_bound(ver, ver+v, qq) - ver;
			qq.MP(MP(), MP());
			q2 = upper_bound(ver, ver+v, qq) - ver;
			for(int j = q1 ; j < q2 ; j++){
				if(y1 >= ver[j].FF.SS && y1 <= ver[j].SS.SS)
					qcnt++;
			}
		}
	}
	x1 = -INF;
	y1 = -INF;
	for(int i = 0 ; i < v ; i++){
		if(x1 == ver[i].FF.FF){
			if(y1 < ver[i].FF.SS){
				y1 = ver[i].SS.SS;
				cnt += (lli)(ver[i].SS.SS - ver[i].FF.SS + 1);	
			}
			else{
				if(y1 < ver[i].SS.SS){
					cnt += (lli)(ver[i].SS.SS - y1);
					y1 = ver[i].SS.SS;
				}
			}
		}
		else{
			y1 = ver[i].FF.SS;
			x1 = ver[i].SS.FF;
			cnt += (lli)(ver[i].SS.SS - ver[i].FF.SS + 1);
		}
	}
	cnt -= (lli)qcnt;
	cout << cnt;
	return 0;
}