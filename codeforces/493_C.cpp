#include <bits/stdc++.h>
#define N 200005
#define FF first
#define SS second
using namespace std;
map < int, pair < int, int > > mp;
map < int, pair < int, int > > :: iterator it;
int main(){
	int n, m, x, s1, s2, tval, ans1, ans2, val, x1, x2;
	scanf("%d", &n);
	s1 = s2 = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		(mp[x].FF)++;
		s1++;
	}
	scanf("%d", &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &x);
		(mp[x].SS)++;
		s2++;
	}
	ans1 = 3*s1;
	ans2 = 3*s2;
	val = 3 * (s1 - s2);
	x1 = 0;
	x2 = 0;
	for(it = mp.begin() ; it != mp.end() ; it++){
		x1 += it->SS.FF;
		x2 += it->SS.SS;
		tval = 3*((s1-x1)-(s2-x2))+2*(x1-x2);
		if(val < tval){
			ans1 = 3*(s1-x1)+2*x1;
			ans2 = 3*(s2-x2)+2*x2;
			val = tval;
		}
	}
	printf("%d:%d", ans1, ans2);
	return 0;
}