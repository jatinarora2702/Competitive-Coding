#include <bits/stdc++.h>
using namespace std;
class graph{
	int v;
	vector < vector < pair < pair < int, int> , int > > > dp;
	list < pair < int, int > > *adj; 
public:
	graph(int v_) : v(v_){
		dp = vector < vector < pair < pair < int , int> , int > > > (v);
		adj = new list < pair < int , int > > [v];
	}
	void add_edge(int x, int y, int w){
		adj[x].push_back(make_pair(y, w));
		int len = 0;
		for(int  i= 0 ; i < dp[x].size() ; i++){
			if(dp[x][i].first.second < w and len < dp[x][i].second)
				len = dp[x][i].second;
		}
		len++;
		dp[y].push_back(make_pair(make_pair(x,w), len));
		list < pair < int, int > > :: iterator it;
		queue < int > q;
		q.push(y);
		//printf("apapapapapaapapapaapap\n");
		while(!q.empty()){
			int s = q.front();
			q.pop();
			//cout << "s=" << s+1 << endl;
			//print();
			for(it = adj[s].begin() ; it != adj[s].end() ; it++){
				if(it->second > w){
					for(int i = 0 ; i < dp[it->first].size() ; i++){
						if(dp[it->first][i].first.first == s){
							(dp[it->first][i].second)+=len;
							q.push(it->first);
						}
					}
				}
			}	
		}
	}
	void get_ans(){
		int max = 0;
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < dp[i].size() ; j++)
				if(dp[i][j].second > max)
					max = dp[i][j].second;
		}
		printf("%d", max);
	}
	void print(){
		for(int i = 0 ; i < v ; i++){
			for(int j = 0 ; j < dp[i].size() ; j++){
				printf("[(%d %d) %d] ", dp[i][j].first.first, dp[i][j].first.second, dp[i][j].second);
			}
			printf("\n");
		}
	}
};
int main(){
	int n, m, x, y, w;
	scanf("%d%d", &n, &m);
	graph g(n);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		x--; y--;
		g.add_edge(x, y, w);
	}
	//printf("pp\n");
	//g.print();
	g.get_ans();
	return 0;
}