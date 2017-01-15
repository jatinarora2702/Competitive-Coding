#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#define INF 1000000007
using namespace std;
class graph{
	int v;
	list <int > *adj;
	vector < int > circle, dist;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		vector < int > temp(v,0), tempdist(v, INF);
		circle = temp;
		dist = tempdist;
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs(){
		int *visited;
		visited = new int[v];
		for(int j = 0 ; j < v ; j++){
			for(int i = 0 ; i < v ; i++)
				visited[i] = 0;
			dfs_circle(j, visited, -1);	
		}
		for(int i = 0 ; i < v ; i++){
			if(circle[i] == 1){
				for(int j = 0 ; j < v ; j++)
					visited[j] = 0;
				dist[i] = 0;
				dfs_visit(i, visited, 0);
			}
		}
		for(int i = 0 ; i < v ; i++)
			printf("%d ", dist[i]);
	}
	void dfs_circle(int s, int *visited, int p){
		visited[s] = 1;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0)
				dfs_circle(*it, visited, s);
			else if(*it != p){
				circle[s] = 1;
				circle[*it] = 1;
			}
		}
	}
	void dfs_visit(int s, int *visited, int val){
		visited[s] = 1;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++) {
			if(visited[*it] == 0){
				if(dist[*it] > val+1)
					dist[*it] = val+1;
				dfs_visit(*it, visited, val+1);
			}
		}
	}
};
int main(){
	int n, x, y;
	scanf("%d", &n);
	graph g(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	g.dfs();
	return 0;
}