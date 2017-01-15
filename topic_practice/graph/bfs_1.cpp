#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define PB push_back
#define N 100005
using namespace std;
vector < int > g[N];
queue < int > q;
int v[N], n, m;
void bfs(int s){
	int u;
	for(int i = 0 ; i < n ; i++)
		v[i] = 0;
	q.push(s);
	v[s] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		printf("%d ", u);
		for(int i = 0 ; i < g[u].size() ; i++){
			if(v[g[u][i]] == 0){
				q.push(g[u][i]);
				v[g[u][i]] = 1;
			}
		}
	}
}
int main(){
	int x, y, s;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		// x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	scanf("%d", &s);
	// s--;
	bfs(s);
	return 0;
}