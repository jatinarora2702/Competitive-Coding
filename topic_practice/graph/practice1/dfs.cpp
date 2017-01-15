#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100000
using namespace std;
vector < pair < int, int > > g[N];
int visited[N];
int n, m;
void dfs_visit(int s){
	visited[s] = 1;
	printf("%d ", s);
	for(int i = 0 ; i < g[s].size() ; i++){
		if(visited[g[s][i].FF] == 0)
			dfs_visit(g[s][i].FF);
	}
}
void dfs(int s){
	dfs_visit(s);
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0)
			dfs_visit(i);
	}
}
int main() {
	int x, y, w, s, f;
	scanf("%d%d", &n, &m);
	printf("is the graph undirected: ");
	scanf("%d", &f);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g[x].PB(MP(y, w));
		if(f == 1)
			g[y].PB(MP(x, w));
	}
	for(int i = 0 ; i < n ; i++){
		cout << i << " : ";
		for(int j = 0 ; j < g[i].size() ; j++){
			cout << "(" << g[i][j].FF << " , " << g[i][j].SS << "), ";
		}
		cout << endl;
	}
	scanf("%d", &s);
	dfs(s);
	printf("\n");
	return 0;
}