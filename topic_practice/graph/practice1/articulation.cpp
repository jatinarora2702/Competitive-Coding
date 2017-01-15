#include <bits/stdc++.h>
#define N 100000
#define PB push_back
using namespace std;
vector < int > g[N];
int visited[N], n, m, disc[N], low[N], parent[N], isap[N];
void findart_visit(int s){
	static int t = 1;
	int cnt = 0;
	visited[s] = 1;
	disc[s] = low[s] = t++;
	for(int i = 0  ; i < g[s].size() ; i++){
		if(visited[g[s][i]] == 0){
			parent[g[s][i]] = s;
			cnt++;
			findart_visit(g[s][i]);
			low[s] = min(low[s], low[g[s][i]]);
			if(parent[s] != -1 && low[g[s][i]] >= disc[s])
				isap[s] = 1;
			if(parent[s] == -1 && cnt > 1)
				isap[s] = 1;
		}
		else if(g[s][i] != parent[s])
			low[s] = min(low[s], disc[g[s][i]]);
	}
}
void findart(){
	for(int i = 0 ; i < n ; i++){
		parent[i] = -1;
		isap[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0)
			findart_visit(i);
	}
}
int main() {
	int x, y, k;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		g[x].PB(y);
		g[y].PB(x);
	}
	findart();
	// cout << "disc: ";
	// for(int i = 0 ; i < n ; i++){
	// 	cout << disc[i] << " ";
	// }
	// cout << endl;
	// cout << "low: ";
	// for(int i = 0 ; i < n ; i++){
	// 	cout << low[i] << " ";
	// }
	// cout << endl;
	for(int i = 0 ; i < n ; i++){
		if(isap[i] != -1)
			printf("%d ", i);	
	}
	return 0;
}