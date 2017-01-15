#include <bits/stdc++.h>
#define N 100000
#define PB push_back
using namespace std;
int n, m, visited[N];
vector < int > g[N];
int main() {
	int x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		g[x].PB(y);
	}
	return 0;
}