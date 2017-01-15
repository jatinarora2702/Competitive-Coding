#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, *arr;
	list < pair < int, int > > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < pair < int, int > > [v];
		arr = new int[v];
		for(int i = 0 ; i < v ; i++)
			arr[i] = 0;
	}
	void add_edge(int x, int y, int w) {
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	void dfs(){
		int f, cnt;
		int *visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		f = dfs_visit(0, visited);
		cnt = 0;
		for(int i = 0 ; i < v ; i++){
			if(arr[i] == 1)
				cnt++;
		}
		printf("%d\n", cnt);
		for(int i = 0 ; i < v; i++){
			if(arr[i] == 1)
				printf("%d ", i+1);
		}
	}
	int dfs_visit(int s, int *visited){
		int f,k;
		f = k = 0;
		visited[s] = 1;
		list < pair < int, int > > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[(*it).first] == 0){
				if((*it).second == 2){
					//cout << "yy\n";
					arr[(*it).first] = 1;
					arr[s] = 0;
					f = 1;//k = 1;
				}
				k = dfs_visit((*it).first, visited);
				if(k == 1){// and k == 0){
					arr[s] = 0;
				}
			}
		}
		//cout << "s=" << s << " f=" << f << endl;
		return f;
	}
};
int main() {
	int n, x, y, w;
	scanf("%d", &n);
	graph g(n);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d%d", &x, &y, &w);
		x--; y--;
		g.add_edge(x, y, w);
	}
	g.dfs();
	return 0;
}