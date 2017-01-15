#include <bits/stdc++.h>
#define N 10000
#define PB push_back
using namespace std;
vector < int > g[N];
stack < int > stk;
int visited[N], f;
void findpath(int s, int v){
	stk.push(s);
	visited[s] = 1;
	if(s == v){
		f = 1;
		return;
	}
	for(int i = 0 ; i < g[s].size() ; i++){
		if(visited[g[s][i]] == 0){
			findpath(g[s][i], v);
			if(f == 1)
				return;
		}
	}
	stk.pop();
}
int main() {
	int n, m, x ,y;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		g[x].PB(y);
		g[y].PB(x);
	}
	scanf("%d%d", &x, &y);
	f = 0;
	findpath(x, y);
	if(f == 1){
		while(!stk.empty()){
			printf("%d ", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	else
		printf("no path\n");
	return 0;
}