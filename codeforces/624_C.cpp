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
pair < int, int > p;
map < pair < int, int > , int > mp, mp1;
int visited[N], n, m;
void dfs_visit(int v){
	visited[v] = 1;
	s[v] = 'a';
	for(int i = 0 ; i < g[v].size() ; i++){
		if(g[g[v][i]].size() < n-1 && visited[g[v][i]] == 0){
			dfs_visit(g[v][i]);
		}
	}
}
int main(){
	int x, y, j, f;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
		p = MP(x, y);
		mp[p] = 1;
		p = MP(y, x);
		mp[p] = 1;
	}
	// f = 1;
	// for(int i = 0 ; i < pv.size() ; i++){
	// 	p = MP(pv[i].SS, pv[i].FF);
	// 	if(mp.count(p) == 0){
	// 		f = 0;
	// 		break;
	// 	}
	// }
	// if(f == 0){
	// 	printf("No\n");
	// 	return 0;
	// }
	f = 0;
	for(int i = 0 ; i < n ; i++){
		if(g[i].size() == n-1){
			s[i] = 'b';
		}
		else{
			j = i;
			f = 1;
		}
	}
	if(f == 1)
		dfs_visit(j);
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0 && g[i].size() < n-1)
			s[i] = 'c';
	}

	s[n] = '\0';
	// printf("s=%s\n", s);
	f = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1; j < n ; j++){
			if(abs(s[i] - s[j]) <= 1){
				p = MP(i, j);
				mp1[p] = 1;
				if(mp.count(p) == 0){
					f = 0;
					break;
				}
				p = MP(j, i);
				mp1[p] = 1;
				if(mp.count(p) == 0){
					f = 0;
					break;
				}
			}
		}
	}
	if(f == 0){
		printf("No\n");
	}
	else{
		if(mp.size() != mp1.size()){
			printf("No\n");
		}
		else{
			printf("Yes\n%s\n", s);	
		}
	}
	return 0;
}