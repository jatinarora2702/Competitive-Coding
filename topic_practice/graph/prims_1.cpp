#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define N 100005
#define pii pair < int, int >
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

const int INF = 1e9 + 7;

struct cmp{
	bool operator()(const pii& a, const pii& b){
		return a.FF < b.FF;
	}
};

vector < pii > g[N];
priority_queue < pii, vector < pii > , less < pii > > pq;
// priority_queue < pii, vector < pii > , cmp > pq;		// also works

int d[N], inc[N];

int main() {
	int n, m, u, v, w, s, c;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &u, &v, &w);
		// u--, v--, w--;
		g[u].PB(MP(v, w));
		g[v].PB(MP(u, w));
	}
	scanf("%d", &s);
	// s--;
	for(int i = 0 ; i < n ; i++){
		d[i] = INF;
		inc[N] = 0;
	}
	d[s] = 0;
	pq.push(MP(0, s));
	while(!pq.empty()){
		u = pq.top().SS;
		c = pq.top().FF;
		pq.pop();
		if(inc[u] == 1)
			continue;
		inc[u] = 1;
		for(int i = 0 ; i < g[u].size() ; i++){
			v = g[u][i].FF;
			w = g[u][i].SS;
			if(inc[v] == 0 && d[v] > w){
				d[v] = w;
				pq.push(MP(w, v));
			}
		}
	}
	for(int i = 0 ; i < n ; i++)
		printf("%d ", d[i]);
	printf("\n");
	return 0;
}