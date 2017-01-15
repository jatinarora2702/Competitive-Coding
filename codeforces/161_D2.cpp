#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 50005
using namespace std;
vector < int > g[N];
set < pair < int , int > > s;
set < pair < int , int > > :: iterator it;
int n, k;
void dfs_visit(int u, int v, int p, int cnt){
	if(cnt > k)
		return;
	if(cnt == k){
		if(u < v){
			// cout << u << " " << v << endl;
			s.insert(MP(u, v));
		}
		else{
			// cout << v << " " << u << endl;
			s.insert(MP(v, u));
		}
		return;
	}
	for(int i = 0 ; i < g[v].size() ; i++){
		if(g[v][i] != p)
			dfs_visit(u, g[v][i], v, cnt+1);
	}
}
int main(){
	int x, y;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	// cout << "inp over\n";
	for(int i = 0 ; i < n ; i++)
		dfs_visit(i, i, -1, 0);
	// cout << "printing set:\n";
	// for(it = s.begin() ; it != s.end() ; it++){
	// 	cout << it->FF << " " << it->SS << endl;
	// }
	cout << s.size();
	return 0;
}