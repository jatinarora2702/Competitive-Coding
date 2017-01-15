#include <bits/stdc++.h>
using namespace std;
int dfs(vector < int >&p ,vector < int >& visited, int s, int& cnt);
int main() {
	int n,cnt,s,smax,max;
	scanf("%d",&n);
	vector < int > p(n);
	vector < int > visited(n,0);
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d",&p[i]);
		if(p[i]!= -1)
			p[i]--;
	}
	cnt = 1;
	max = 0;
	smax = 0;
	for(int i = 0 ; i < n ; i++ ) {
		if(true) {
			s = dfs(p,visited,i,cnt);
			if(max < cnt) {
				max = cnt;
				smax = s;
			}
			cnt = 1;
		}
	}
	//s = dfs(p,visited,smax,cnt);
	cout << max;
	return 0;
}
int dfs(vector < int >&p ,vector < int >& visited, int s, int& cnt) {
	visited[s] = 1;
	if(p[s] == -1) {
		return s;
	}
	cnt++;
	return dfs(p,visited,p[s],cnt);
}