#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define pii pair < int , int > 
#define N 100005
const int INF = 1e9 + 7;
using namespace std;
vector < pii > g[N];
int d[N];
priority_queue < pii , vector < pii >, greater < pii > > pq;
int main(){
	int n, m, u, v, w, c, s;
	printf("Enter the no. of vertices : ");
	scanf("%d", &n);
	printf("Enter the no. of edges : ");
	scanf("%d", &m);
	printf("Enter the vertices as (x, y, z) : (z is wt. of edge (x, y)) (consider undirected graph) :\n");
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &u, &v, &w);
		// u--, v--, w--;
		g[u].PB(MP(v, w));
		g[v].PB(MP(u, w));
	}
	printf("Enter the source vertex : ");
	scanf("%d", &s);
	// s--;
	for(int i = 0 ; i < n ; i++)
		d[i] = INF;
	d[s] = 0;
	pq.push(MP(0, s));
	while(!pq.empty()){
		u = pq.top().SS;
		c = pq.top().FF;
		pq.pop();
		if(d[u] < c)
			continue;
		for(int i = 0 ; i < g[u].size() ; i++){
			v = g[u][i].FF;
			w = g[u][i].SS;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push(MP(d[v], v));
			}
		}
	}
	printf("dijkstra distances are :\n");
	for(int i = 0 ; i < n ; i++)
		printf("%d ", d[i]);
	printf("\n");
	return 0;
}