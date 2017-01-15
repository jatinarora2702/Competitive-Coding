#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define N 100000
using namespace std;
vector < pair < int, int > > g[N];
int disc[N], low[N], parent[N], visited[N], isap[N], n, m;
void getap_visit(int s){
	static int t = 1;
	cout << "entered\n";
	int cnt = 0;
	visited[s] = 1;
	disc[s] = low[s] = t++;
	for(int i = 0 ; i < g[s].size() ; i++){
		cout << "i am here\n";
		if(visited[g[s][i].FF] == 0){
			cnt++;
			parent[g[s][i].FF] = s;
			getap_visit(g[s][i].FF);
			low[s] = min(low[s], low[g[s][i].FF]);
			if(parent[s] == -1 && cnt > 1)
				isap[s] = 1;
			if(parent[s] != -1 && low[g[s][i].FF] >= disc[s])
				isap[s] = 1;
		}
		else if(g[s][i].FF != parent[s])
			low[s] = min(low[s], disc[g[s][i].FF]);
	}
}
void getap(){
	for(int i = 0  ; i < n ; i++){
		parent[i] = -1;
		isap[i] = -1;
	}
	cout << "tt\n";
	for(int i = 0 ; i < n ; i++){
		visited[i] = 0;
	}
	cout << "here\n";
	cout << "n=" << n << endl;
	for(int i = 0 ; i < n ; i++){
		cout << "i am here\n";
		if(visited[i] == 0){
			printf("in the loop\n");
			getap_visit(i);
		}
	}
	cout << "end\n";
}
int main() {
	int x, y, w;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g[x].PB(MP(y, w));
		g[y].PB(MP(x, w));
	}
	cout << "nn=" << n << endl;
	cout << "disc: ";
	for(int  i= 0  ; i < n ; i++){
		cout << disc[i] << " ";
	}
	cout << endl;
	cout << "ynn=" << n << endl;
	cout << "low: ";
	for(int  i= 0  ; i < n ; i++){
		cout << low[i] << " ";
	}
	cout << "nnn=" << n << endl;
	cout << endl;
	cout << "here n:" << n << endl;
	getap();
	for(int i = 0 ; i < n ; i++){
		if(isap[i] != -1)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}
