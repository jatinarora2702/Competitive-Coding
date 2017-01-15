#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
class graph{
	int v, n, minm;
	list < int, pair < int, int > > *adj;
	void graph(int v_) : v(v_){
		adj[i] = new list < int, pair < int, int > > [v];
		minm = INF;
	}
	void add_edge(int x, int y, int w){
		adj[x] = make_pair(x, make_pair(y, w));
		adj[y] = make_pair(y, make_pair(x, w));
	}
	int dfs(){
		int *visited = new int[v];
		vector < int > vec[v];
		for(int i  = 0 ; i < n ; i++)
			visited[i] = 0;
		for(int i = 0 ; i < n ; i++){
			if(visited[i] == 0)
				dfs_visit(i, visited, vec);
		}
		return minm;
	}
	void dfs_visit(int s, int *visited, vector < int > &vec){
		vec.push_back(s);
	}
};
int main(){
	int t, n, l, r, a, b, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &l, &r);
		graph g(n);
		for(int i = 0 ; i < n; i++){
			scanf("%d%d%d", &a, &b, &c);
			
		}
	}
}