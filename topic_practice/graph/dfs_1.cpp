#include <iostream>
#include <cstdio>
#include <vector>
#define PB push_back
#define N 100005
using namespace std;

vector < int > g[N];
int v[N], n, m, x, y;
void dfs_visit(int s){
	v[s] = 1;
	printf("%d ", s);
	for(int i = 0 ; i < g[s].size() ; i++){
		if(v[g[s][i]] == 0)
			dfs_visit(g[s][i]);
	}
}
void dfs(int s){
	for(int i = 0 ; i < n ; i++)
		v[i] = 0;
	dfs_visit(s);
	for(int i = 0 ; i < n ; i++){
		if(v[i] == 0)
			dfs(i);
	}
}
int main(){
	int s;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		// x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	scanf("%d", &s);
	// s--;
	dfs(s);
	return 0;
}