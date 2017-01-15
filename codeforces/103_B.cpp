#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
int cnt = 0;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		cnt = 0;
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs_visit(int s, int *visited, int ps){
		//cout << "yy : s = " << s << endl;
		if(cnt > 1)
			return;
		//cout << "ff : cnt = " << cnt << endl;
		visited[s] = 1;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0)
				dfs_visit(*it, visited, s);
			else if (visited[*it] == 1){
				//cout << "rr\n";
				if(*it != ps){
					//cout << "s = " << s << " *it = " << *it << endl;
					//cout << "kk\n";
					cnt++;
				}
			}
		}
		visited[s] = 2;
	}
	void dfs(){
		int *visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		dfs_visit(0, visited, -1);
		for(int i = 0 ; i < v ; i++){
			if(visited[i] == 0){
				cnt = 0;
				break;
			}
		}
		if(cnt == 1)
			printf("FHTAGN!");
		else
			printf("NO");
	}
};
int main(){
	int n, e, x, y;
	scanf("%d%d", &n, &e);
	graph g(n);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	g.dfs();
	return 0;
}