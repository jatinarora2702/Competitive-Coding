#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#define INF 1000000007
using namespace std;
class graph{
	int v, e;
	list < int > *adj;
	vector < vector < int > > dist;
public:
	graph(int v_, int e_) : v(v_), e(e_) {
		adj = new list < int > [v];
		dist = vector < vector < int > > (v, vector < int > (v, INF));
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void bfs(int s){
		list < pair < int, int > > temp;
		list < int > :: iterator it;
		pair < int , int > p;
		int *visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		visited[s] = 1;
		temp.push_back(make_pair(s, 0));
		while(temp.size() != 0){
			p = temp.front();
			temp.pop_front();
			dist[s][p.first] = p.second;
			for(it = adj[p.first].begin() ; it != adj[p.first].end() ; it++){
				if(visited[*it] == 0){
					visited[*it] = 1;
					temp.push_back(make_pair(*it, p.second + 1));
				}
			}
		}
	}
	void roads(int s1, int f1, int w1, int s2, int f2, int w2){
		int max, temp;
		for(int i = 0 ; i < v ; i++)
			bfs(i);
		//print(dist, v, v);
		if(dist[s1][f1] > w1 or dist[f2][s2] > w2)
			printf("-1");
		else{
			max = e - dist[s1][f1] - dist[s2][f2];
			//printf("max=%d\n", max);
			for(int i = 0 ; i < v ; i++){
				for(int j = 0 ; j < v ; j++){
					if(dist[s1][i] == INF or dist[s2][i] == INF or dist[i][j] == INF or dist[j][f1] == INF or dist[j][f2] == INF)
						continue;
					temp = e - dist[s1][i] - dist[s2][i] - dist[i][j] - dist[j][f1] - dist[j][f2];
					//printf("%3d ", temp);
					if(temp > max)
						max = temp;
				}
				//printf("\n");
			}
			printf("%d", max);	
		}
	}
	void print(vector < vector < int > > &a, int n, int m){
		printf("printing..\n");
		for(int i = 0 ;  i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				printf("%10d ", a[i][j]);
			}
			printf("\n");
		}
	}
};
int main() {
	int n, e, x, y, x1, y1, w, w1;
	scanf("%d%d", &n, &e);
	graph g(n, e);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	scanf("%d%d%d%d%d%d", &x, &y, &w, &x1, &y1, &w1);
	x--, y--, x1--, y1--;
	g.roads(x, y, w, x1, y1, w1);
	return 0;
}