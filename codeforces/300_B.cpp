#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, *visited;
	list < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		visited = new int[v];
		for(int i = 0 ; i < v ; i++)
			visited[i] = 0;
	}
	int add_edge(int x, int y){
		if(adj[x].size() < 2 and adj[y].size() < 2) {
			adj[x].push_back(y);
			adj[y].push_back(x);
			visited[x] = visited[y] = 1;
			return 1;
		}
		else
			return 0;
	}
	void alott(){
		int j, cnt;
		list < int > :: iterator it;
		for(j = 0 ; j < v ; j++){
			if(adj[j].size() == 0)
				break;
		}
		for(int i = 0 ; i < v ; i++){
			if(adj[i].size() == 2 and visited[i] == 1){
				printf("%d ", i+1);
				visited[i] = 2;
				for(it = adj[i].begin() ; it != adj[i].end() ; it++){
					printf("%d ", *it+1);
					visited[*it] = 2;
				}
				printf("\n");
			}
			else if(adj[i].size() == 1 and visited[i] == 1){
				printf("%d %d %d\n", i+1, adj[i].front()+1, j+1);
				visited[i] = 2;
				visited[adj[i].front()] = 2;
				visited[j] = 2;
				j++;
				while(j < v){
					if(adj[j].size() == 0)
						break;
					j++;
				}
			}
		}
		cnt = 0;
		for(; j < v ; j++){
			if(visited[j] == 0){
				printf("%d ", j+1);
				cnt++;
				if(cnt == 3)
					printf("\n");
			}
		}
	}
};
int main() {
	int n, e, x, y, f;
	scanf("%d%d", &n, &e);
	graph g(n);
	f = 1;
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		if(g.add_edge(x, y) == 0)
			f = 0;
	}
	if(f == 0)
		printf("-1");
	else{
		g.alott();
	}
	return 0;
}