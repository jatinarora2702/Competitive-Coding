#include <bits/stdc++.h>
using namespace std;
/*int dfs_visit(vector < vector < int > >& g, int s) {
	visited[s] = 1;
	if(g[s].size())
}*/
int main() {
	int n,m,u,v,k;
	scanf("%d%d",&n,&m);
	vector < vector < int  > > g(n);
	for(int i = 0 ; i < m ; i++ ) {
		scanf("%d%d",&u,&v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i =  0 ; i < n ; i++ ){ 
		if(g[i].size() == 0) {
			k = i;
			break;
		}
	}
	/*vector < int > visited(n,0);
	for(int i = 0 ; i < n ; i++ ) {
		if(visited[i] == 0) {
			k = dfs_visit(g);
			if(k != -1) 
				break;
		}
	}*/
	printf("%d",n-1);
	for(int i = 0 ; i < n ; i++ ) {
		if(i == k)
			continue;
		printf("\n%d %d",k+1,i+1);
	}
}