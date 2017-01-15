#include <bits/stdc++.h>
#define N 50005
#define PB push_back
using namespace std;
vector < int > g[N];
vector < int > lev[505];
queue < int > q;
int dp[N][505], a[N];
int main() {
	int n, k, x, y;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	q.push(0);
	visited[0] = 1;
	lev[0].PB(0);
	a[0] = 0;
	while(!q.empty()){
		x = q.top();
		q.pop();
		for(int i = 0 ; i < g[x].size() ; i++){
			if(visited[g[x][i]] == 0){
				visited[g[x][i]] = 1;
				lev[a[x]+1].PB(g[x][i]);
				a[g[x][i]] = a[x] + 1;
				q.push(g[x][i]);
			}
		}
		visited[x] = 2;
	}
	for(l = 0 ; l < N ; l++){
		if(lev[l].size() == 0)
			break;
	}
	l--;
	for(int i = l ; i >= 0 ; i--){
		dp[]
	}
}