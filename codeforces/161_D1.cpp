#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
class graph{
	int v;
	vector < int > *adj, *dp;
public:
	graph(int v_) : v(v_) {
		adj = new vector < int > [v];
		dp = new vector < int > [v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
		dp[x].push_back(1);
		dp[y].push_back(1);
	}
	int findin(int m, int x, int y){
		int fx, fy;
		fx = fy = 0;
		for(int i = 0 ; i < adj[m].size() ; i++){
			if(adj[m][i] == x) fx = 1;
			if(adj[m][i] == y) fy = 1;
		}
		if(fx == 1 and fy == 1)
			return 1;
		return 0;
	}
	void count(int cnt){
		ulli a = 0;
		for(int k = 2 ; k <= cnt ; k++){
			for(int i = 0 ; i < v ; i++){
				for(int j = 0 ; j < adj[i].size() ; j++){
					for(int m = 0 ; m < v ; m++){
						if(findin(m, i, adj[i][j])){
							if(dp[i][m] + dp[m][adj[i][j]] < dp[i][adj[i][j]])
								dp[i][adj[i][j]] = dp[i][m] + dp[m][adj[i][j]];
						}
					}
				}
				for(int i1 = 0 ; i1 < v ; i1++){
					printf("%d : ", i1);
					for(int j1 = 0 ; j1 < adj[i1].size() ; j1++){
						printf("%d ", dp[i1][adj[i1][j1]]);
					}
					printf("\n");
				}
			}
		}
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < adj[i].size() ; j++){
				if(dp[i][j] == cnt)
					a++;
			}
		}
		a = a / (ulli)2;
		cout << a;
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