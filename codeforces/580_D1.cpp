#include <iostream>
#include <stdio.h>
#include <utility>
#include <set>
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define N 200005
#define INF 1000000000
using namespace std;
int x[N], ships[N];
set < pair < int , int > > s;
int main() {
	int n, k, a, m, cnt, mv, kold, kl, ku;
	pair < int, int > p, plb, pl, pu;
	set < pair < int, int > > :: iterator it;
	scanf("%d%d%d%d", &n, &k, &a, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &x[i]);
	}
	cnt = (n + 1) / (a + 1);
	mv = 0;
	s.insert(MP(n,1));
	if(cnt >= k){
		for(int i = 0 ; i < m ; i++){
			p = MP(x[i], -1);
			it = s.lower_bound(p);
			plb = *(it);
			if(it != s.end()){
				s.erase(it);
				pl = MP(x[i]-1, plb.ss);
				pu = MP(plb.ff, x[i]+1);
				s.insert(pl);
				s.insert(pu);
				kold = (plb.ff - plb.ss + 2) / (a + 1);
				kl = (pl.ff - pl.ss + 2) / (a + 1);
				ku = (pu.ff - pu.ss + 2) / (a + 1);
				cnt = cnt - kold + kl + ku;
				if(cnt < k){
					mv = i+1;
					break;
				}
			}
		}
		if(mv == 0)
			mv = -1;
	}
	printf("%d", mv);
	return 0;
}