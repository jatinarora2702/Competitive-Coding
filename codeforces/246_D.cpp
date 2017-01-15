#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
class graph{
	int v, *vc, *idx;
	vector < pair < int, int > > carr;
	list < int > *adj;
public:
	graph(int v_, int *arr) : v(v_) {
		adj = new list < int > [v];
		vc = new int[v];
		idx = new int[v];
		for(int i = 0 ; i < v ; i++)
			vc[i] = arr[i];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs(){
		int *visited, max;
		visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
		for(int i = 0 ; i < v ; i++){
			idx[i] = -1;
			for(int j = 0 ; j < carr.size() ; j++){
				if(carr[j].first == vc[i]){
					idx[i] = j;
					break;
				}
			}
			if(idx[i] == -1){
				carr.push_back(make_pair(vc[i], 0));
				idx[i] = carr.size()-1;
			}
		}
		for(int i = 0 ; i < v ; i++){
			if(visited[i] == 0){
				dfs_visit(i, visited);
			}
		}
		max = 0;
		for(int i = 0 ; i < carr.size() ; i++){
			if(carr[max].second < carr[i].second)
				max = i;
			else if(carr[max].second == carr[i].second){
				if(carr[max].first > carr[i].first)
					max = i;
			}
		}
		printf("%d", carr[max].first);
	}
	void dfs_visit(int s, int *visited){
		visited[s] = 1;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0){
				if(vc[*it] != vc[s]){
					carr[idx[*it]].second++;
					carr[idx[s]].second++;	
				}
				dfs_visit(*it, visited);
			}
		}
	}
};
int main(){
	int n, e, *arr, x, y;
	scanf("%d%d", &n, &e);
	arr = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &arr[i]);
	}
	graph g(n, arr);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	g.dfs();
	return 0;
}