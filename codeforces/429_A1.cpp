#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v;
	list < int > *adj;
	int *g, *init;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		g = new int[v];
		init = new int[v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs_visit(int s, int f){
		int f1;
		init[s] = init[s] ^ f;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(*it > s){
				f1 = (f == 0) ? 1 : 0;
				dfs_visit(*it, f1);
			}
		}
	}
	void dfs(){
		int *arr = new int[v];
		for(int i = 0 ; i < v ; i++)
			arr[i] = 0;
		for(int i = 0 ; i < v ; i++)
			scanf("%d", &init[i]);
		for(int i = 0 ; i < v ; i++)
			scanf("%d", &g[i]);
		int cnt = 0;
		for(int i = 0 ;  i < v ; i++){
			if(init[i] != g[i]){
				cnt++;
				arr[i] = 1;
				dfs_visit(i, 1);
			}
		}
		printf("%d\n", cnt);
		for(int i = 0 ; i < v ; i++){
			if(arr[i] == 1)
				printf("%d\n", i+1);
		}
	}
};
int main(){
	int n, x, y;
	scanf("%d", &n);
	graph gr(n);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		gr.add_edge(x, y);
	}
	gr.dfs();
	return 0;
}