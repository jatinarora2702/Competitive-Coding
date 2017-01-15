#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
const int N = 3001;
vector < int > adj[N];
int d[N][N];
int main(){
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	memset(d, -1, sizeof d);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0 ; i < n ; i++){
		queue < int > q;
		q.push(i);
		d[i][i] = 0;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			for(int j = 0 ; j < adj[s].size() ; j++){
				int to = adj[s][j];
				if(d[i][to] == -1){
					d[i][to] = d[i][s] + 1;
					q.push(to);
				}
			}
		}
	}
	int s[2], t[2], w[2];
	for(int i = 0 ; i < 2 ; i++){
		scanf("%d%d%d", &s[i], &t[i], &w[i]);
		s[i]--, t[i]--;
	}
	int ans = m+1;
	for(int k = 0 ; k < 2 ; k++){
		swap(s[0], t[0]);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				int v[] = {d[s[0]][i]+d[i][j]+d[j][t[0]], d[s[1]][i]+d[i][j]+d[j][t[1]]};
				if(v[0] <= w[0] and v[1] <= w[1])
					ans = min(ans, v[0]+v[1]-d[i][j]);
			}
		}
	}
	if(d[s[0]][t[0]] <= w[0] and d[s[1]][t[1]] <= w[1])
		ans = min(ans, d[s[0]][t[0]]+d[s[1]][t[1]]);
	if(ans > m)
		ans = -1;
	else
		ans = m - ans;
	printf("%d", ans);
	return 0;
}