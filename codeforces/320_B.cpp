#include <bits/stdc++.h>
using namespace std;
int k = 0;
void dfs_visit(vector < pair < int , int > > &v, int s, int f, int *visited){
	if(s == f){
		k = 1;
		return;
	}
	visited[s] = 1;
	for(int i = 0 ; i < v.size() ; i++){
		if(visited[i] == 0){
			if(v[i].first < v[s].first and v[i].second > v[s].first)
			dfs_visit(v, i, f, visited);
		else if(v[i].first < v[s].second and v[i].second > v[s].second)
			dfs_visit(v, i, f, visited);	
		}
	}
}
int main(){
	int n, x, y, f;
	vector < pair < int, int > > v;
	pair < int, int > p;	
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d", &f, &x, &y);
		if(f == 1)
			v.push_back(make_pair(x, y));
		else{
			x--; y--;
			int visited[100];
			for(int i = 0 ; i < 100 ; i++)
				visited[i] = 0;
			dfs_visit(v, x, y, visited);
			if(k == 1){
				printf("YES\n");
				k = 0;
			}
			else
				printf("NO\n");
		}
	}
	return 0;
}