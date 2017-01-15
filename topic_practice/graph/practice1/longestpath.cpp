#include <bits/stdc++.h>
#define N 10000
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
const int INF = 1e9+7;
vector < pair < int, int > > g[N];
vector < int > v;
int visited[N], dist[N], n, m;
void topological_visit(int s){
	visited[s] = 1;
	for(int i = 0 ; i < g[s].size() ; i++){
		if(visited[g[s][i].FF] == 0)
			topological_visit(g[s][i].FF);
	}
	v.PB(s);
}
void topological(){
	int b, e, temp;
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0)
			topological_visit(i);
	}
	b = 0;
	e = n-1;
	while(b < e){
		temp = v[b];
		v[b] = v[e];
		v[e] = temp;
		b++;
		e--;
	}
}
void getdist(int s){
	for(int i = 0 ; i < n ; i++)
		dist[i] = -INF;
	dist[s] = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < g[v[i]].size() ; j++){
			if(dist[g[v[i]][j].FF] < dist[v[i]] + g[v[i]][j].SS)
				dist[g[v[i]][j].FF] = dist[v[i]] + g[v[i]][j].SS;
		}
	}
}
int main() {
	int x, y, w, s;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g[x].PB(MP(y, w));
	}
	topological();
	scanf("%d", &s);
	getdist(s);
	for(int i = 0 ; i < n ; i++){
		if(dist[i] == -INF)
			printf("INF ");
		else
			printf("%d ", dist[i]);
	}
	printf("\n");
	return 0;
}