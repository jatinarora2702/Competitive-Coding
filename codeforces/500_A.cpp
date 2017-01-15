#include <bits/stdc++.h>
using namespace std;
void DFS(vector < int >& adj, vector < int >& visited, int s) {
	visited[s] = 1;
	if(adj[s] < adj.size() and visited[adj[s]] == 0) {
		DFS(adj,visited,adj[s]);
	}
	else
		return;
}
int main() {
	int n,t,v;
	scanf("%d%d",&n,&t);
	t--;
	vector < int > adj(n);
	vector < int > visited(n,0);
	for(int i = 0 ; i < n-1 ; i++ ) {
		scanf("%d",&v);
		adj[i] = i+v;
	}
	DFS(adj,visited,0);
	if(visited[t] == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}