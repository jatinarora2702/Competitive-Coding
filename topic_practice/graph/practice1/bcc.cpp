#include <bits/stdc++.h>
#define N 100000
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;
vector < pair < int , int > > g[N];
int disc[N], low[N], parent[N], isap[N], n, m, cnt;
stack < pair < int, int > > stk;
pair < int, int > p;
void getbcc_visit(int s){
	static int t = 0;
	int child = 0;
	disc[s] = low[s] = ++t;
	for(int i = 0 ; i < g[s].size() ; i++){
		if(disc[g[s][i].FF] == -1){
			child++;
			parent[g[s][i].FF] = s;
			stk.push(MP(s, g[s][i].FF));
			getbcc_visit(g[s][i].FF);
			low[s] = min(low[s], low[g[s][i].FF]);
			if((child > 1 && parent[s] == -1) || (parent[s] != -1 && low[g[s][i].FF] >= disc[s])) {
				isap[s] = 1;
				cnt++;
				printf("[");
				while(!stk.empty()){
					p = stk.top();
					printf("(%d,%d)", p.FF, p.SS);
					stk.pop();
					if(p.FF == s && p.SS == g[s][i].FF)
						break;
				}
				printf("]\n");
			}
		}
		else if(g[s][i].FF != parent[s] && disc[g[s][i].FF] < low[s]){
			low[s] = min(low[s], disc[g[s][i].FF]);
			stk.push(MP(s, g[s][i].FF));
		}
	}
}
void getbcc(){
	for(int i = 0 ; i < n ; i++){
		disc[i] = -1;
		parent[i] = -1;
		isap[i] = -1;
	}
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(disc[i] == -1){
			getbcc_visit(i);
			if(!stk.empty()){
				printf("[");
				while(!stk.empty()){
					p = stk.top();
					printf("(%d,%d)", p.FF, p.SS);
					stk.pop();
				}
				printf("]\n");
			}
		}
	}
}
int main() {
	int x, y, w;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		g[x].PB(MP(y, w));
		g[y].PB(MP(x, w));
	}
	getbcc();
	printf("articulation pts: ");
	for(int i = 0 ; i < n ; i++){
		if(isap[i] != -1)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}