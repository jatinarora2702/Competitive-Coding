#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define rep(i, a, b) for(int (i) = (a) ; (i) < (b) ; ++(i))
#define repn(i, a, b) for(int (i) = (a) ; (i) >= (b) ; --(i))
#define S(a) scanf("%d", &(a))
#define S2(a, b) scanf("%d%d", &(a), &(b))
#define P(a) printf("%d\n", (a))
#define P2(a, b) printf("%d %d\n", (a), (b))
#define N 400005

using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;

const int MOD = 1e9+7;
const int INF = 1e9+7;

int p[N], a[N], b[N], visit[N], c[N];
vector < int > g[N], gc[N];
vector < int > :: iterator it;

void dfs_visit(int s, int pr){
	visit[s] = 1;
	gc[s].PB(c[s]);
	b[s] = pr;
	rep(i, 0, g[s].size()){
		if(visit[g[s][i]] == 0 && g[s][i] != pr){
			dfs_visit(g[s][i], s);
			set_union(gc[s].begin(), gc[s].end(), gc[g[s][i]].begin(), gc[g[s][i]].end(), back_inserter(gc[s]));
		}
	}
}
int main(){
	int n, m, x, y;
	S2(n, m);
	rep(i, 0, n){
		S(a[i]);
	}
	rep(i, 0, n-1){
		S2(x, y);
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs_visit(1, 0);
	rep(i, 0, m){
		S(q);
		if(q == 1){
			S2(x, y);
			gs[x].clear();
			gs[x].PB(y);
			
		}
		else{
			S(x);
			P(gc[x].size());
		}
	}
	return 0;
}