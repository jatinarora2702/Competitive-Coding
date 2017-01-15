#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
vector < vector < pair < int , int > > > vec()
int max = 0;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs_visit(int s, int *visited, int c){
		visited[s] = 1;
		if(c > max)
			max = c;
		list < int > :: iterator it;
		if(adj[s].size() == 1)
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0)
				dfsleaf(*it, visited, c+1);
		}
	}
	void dfs(){
		int *visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		for(int i = 0 ; i < v ; i++){
			if(adj[i].size() == 1){
				dfs_visit(i, visited, 0);
				break;
			}
		}
		if(max == 1)
			printf("NO");
		else{
			for(int i = 0 ; i < n ; i++){
				if(adj[i].size() == 1)
					v.push_back(i);
			}
			cnt = 0;
			for(int i = 0 ; i < v.size() ; i++){
				dfs_visit_1(i, visited);
				m = findmax(i);
				if(m == max)
					cnt++;
				if(cnt == 2)
					break;
			}

		}
	}
};
int main(){
	int n, t, x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		graph g(n);
		for(int i = 0 ; i < n-1 ; i++){
			scanf("%d%d", &x, &y);
			g.add_edge(x, y);
		}
		max = 0;
		g.dfs();
	}
	return 0;
}
