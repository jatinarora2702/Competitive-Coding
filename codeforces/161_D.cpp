#include <bits/stdc++.h>
using namespace std;
class graph{
	int v, **dp;
	vector < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new vector < int > [v];
		dp = new int*[v];
		for(int i = 0 ; i < v ; i++)
			dp[i] = new int[v];
		for(int i = 0 ; i < v ; i++)
			for(int j = 0 ; j < v ; j++)
				dp[i][j] = -1;
		for(int i = 0 ; i < v ; i++)
			dp[i][i] = 0;
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void dfs_visit(int s, int *visited){
		visited[s] = 1;
		for(int i = 0 ; i < adj[s].size() ; i++){
			cout << "rtrtrt\n";
			dp[s][adj[s][i]] = 1;
			if(visited[adj[s][i]] == 0){
				dfs_visit(adj[s][i], visited);
				cout << "qpqpq\n";
				for(int j = 0 ; j < v ; j++){
					if(j != s and dp[adj[s][i]][j] != -1){
						if(dp[s][j] == -1 or dp[s][j] > dp[adj[s][i]][j] + 1){
							cout << "tt\n";
							dp[s][j] = dp[adj[s][i]][j] + 1;
						}
					}
				}
			}
		}
		cout << "s=" << s << endl;
		for(int i = 0 ; i < v ; i++){
			printf("%d : ", i);
			for(int j = 0 ; j < v ; j++){
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
	}
	void count(int cnt){
		int k = 0;
		int *visited = new int[v];
		for(int i = 0 ; i < v; i++)
			visited[i] = 0;
		dfs_visit(0, visited);
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < v ; j++){
				if(dp[i][j] == cnt)
					k++;
			}
		}
		printf("%d", k);
	}
};
int main(){
	int n, x, y, k;
	scanf("%d%d", &n, &k);
	graph g(n);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	g.count(k);
	return 0;
}