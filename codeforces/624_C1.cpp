#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 600
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int ONF = 1e9+7;
char s[N];
vector < int > g[N];
map < pair < int, int > , int > mp, mp1;
pair < int, int > p;
int m, n;
int main(){
	int x, y, j, f, fa, fc;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
		p = MP(x, y);
		mp1[p] = 1;
		p = MP(y, x);
		mp1[p] = 1;
	}
	for(int i = 0 ; i < n ; i++)
		s[i] = 'd';
	f = 1;
	for(int i = 0 ; i < n ; i++){
		if(g[i].size() == n-1){
			s[i] = 'b';
			continue;
		}
		fa = 0;
		fc = 0;
		for(int j = 0 ; j < g[i].size() ; j++){
			if(s[g[i][j]] == 'a')
				fa = 1;
			if(s[g[i][j]] == 'c')
				fc = 1;
		}
		if(fa == 1 && fc == 1){
			f = 0;
			break;
		}
		else if(fa == 1)
			s[i] = 'c';
		else
			s[i] = 'a';
	}
	if(f == 0){
		printf("No\n");
	}
	else{
		s[n] = '\0';
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				if(abs(s[i] - s[j]) <= 1){
					p = MP(i, j);
					mp[p] = 1;
					p = MP(j, i);
					mp[p] = 1;
				}
			}
		}
		if(mp.size() != mp1.size())
			printf("No\n");
		else
			printf("Yes\n%s\n", s);
	}
	return 0;
}