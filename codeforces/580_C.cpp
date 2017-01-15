#include <bits/stdc++.h>
#define N 100006
using namespace std;
int a[N];
class graph{
public:
	int v, e, cnt, m1;
	list < int > *adj;
	graph(int v_, int m_) : v(v_), m1(m_) {
		adj = new list < int > [v];
		cnt = 0;
	}
	void add(int x, int  y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void print(){
		printf("printing:\n");
		list < int > :: iterator it;
		for(int i = 0 ; i < v ; i++){
			for(it = adj[i].begin() ; it != adj[i].end() ; it++){
				cout << *it << " ";
			}
			cout << endl;
		}
		printf("printend\n");
	}
	int dfs(){
		int *visited;
		visited = new int[v];
		for(int i = 0;  i < v;  i++)
			visited[i] = 0;
		int k = 0;
		dfs_visit(0, visited, k);
		return cnt;
	}
	void dfs_visit(int s, int *visited, int k){
		visited[s] = 1;
		if(a[s] == 1)
			k++;
		if(a[s] == 0)
			k = 0;
		if(k > m1)
			return;
		int flag = 0;
		list < int > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[*it] == 0){
				flag = 1;
				dfs_visit(*it, visited, k);
			}
		}
		if(flag == 0)
			cnt++;
	}
};
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n ; i++)
		scanf("%d", &a[i]);
	graph g(n, m);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g.add(x, y);
	}
	int k11 = g.dfs();
	printf("%d", k11);
	return 0;
}