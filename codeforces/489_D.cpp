#include <bits/stdc++.h>
using namespace std;
class graph{
	int v;
	vector < int > *adj;
	vector < int > **dp;
public:
	graph(int v_) : v(v_) {
		adj = new vector < int > [v];
		dp = new vector < int >* [v];
		for(int i = 0 ; i < v ; i++)
			dp[i] = new vector < int > [v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
	}
	void get_count(){
		int cnt = 0;
		vector < int > intsec;
		for(int i = 0 ; i < v ; i++)
			sort(adj[i].begin(), adj[i].end());
		//cout << "kk\n";
		/*for(int i = 0 ; i < v ; i++){
			printf("%d : ", i);
			for(int j = 0 ; j < adj[i].size() ; j++){
				printf("%d ", adj[i][j]);
			}
			printf("\n");
		}*/
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < adj[i].size() ; j++){
				for(int k = j+1 ; k < adj[i].size() ; k++){
					//cout << j << " :: " << k << endl;
					cnt += get_intersection(adj[i][j], adj[i][k], i);
				}
			}
		}
		printf("%d", cnt);
	}
	int get_intersection(int a, int b, int k){
		int i, j, m, n, cnt;
		//cout << "aw\n";																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																													
		if(dp[a][b].size() == 0){
			//cout << "bw\n";
			i = j = 0;
			m = adj[a].size();
			n = adj[b].size();
			//cout << "rr\n";
			while(i < m and j < n){
				if(adj[a][i] < adj[b][j])
					i++;
				else if(adj[a][i] > adj[b][j])
					j++;
				else{
					dp[a][b].push_back(adj[a][i]);
					i++; j++;
				}
			}
		}
		cnt = 0;
		for(i = 0 ; i < dp[a][b].size() ; i++)
			if(dp[a][b][i] != k)
				cnt++;
		return cnt;
	}
};
int main() {
	int n, m, x, y, cnt;
	scanf("%d%d", &n, &m);
	graph g(n);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
		//cout << "ee\n";
	}
	g.get_count();
	return 0;
}