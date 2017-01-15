#include <bits/stdc++.h>
#define PB push_back
#define N 10000
using namespace std;
vector < int > g[N], stk;
int visited[N], n, m;
void dfs_visit(int s){
	visited[s] = 1;
	for(int i = 0 ; i < g[s].size() ; i++){
		if(visited[g[s][i]] == 0)
			dfs_visit(g[s][i]);
	}
	stk.PB(s);
}
void dfs(int s){
	dfs_visit(s);
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0)
			dfs_visit(i);
	}
}
int main() {
	int x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		g[x].PB(y);
	}
	dfs(0);
	for(int i = stk.size()-1 ; i >= 0 ; i--)
		printf("%d ", stk[i]);
	printf("\n");
	return 0;
}