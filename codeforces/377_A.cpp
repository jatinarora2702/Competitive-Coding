#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct{
	int x, y;
}node;
int isvalid(char **s, int **visited, int i, int j, int n, int m){
	if(i >= 0 and i < n and j >= 0 and j < m and s[i][j] == '.' and visited[i][j] == 0){
		return 1;
	}
	return 0;
}
void dfs_visit(int si, int sj, char **s, int n, int m, int **visited, int max) {
	static int fncnt = 0;
	if(fncnt == max)
		return;
	visited[si][sj] = 1;
	fncnt++;
	if(isvalid(s,visited, si,sj+1,n,m)){
		dfs_visit(si,sj+1,s,n,m,visited,max);
	}
	if(isvalid(s,visited, si+1,sj,n,m)){
		dfs_visit(si+1,sj,s,n,m,visited,max);
	}
	if(isvalid(s,visited, si-1,sj,n,m)){
		dfs_visit(si-1,sj,s,n,m,visited,max);
	}
	if(isvalid(s,visited, si,sj-1,n,m)){
		dfs_visit(si,sj-1,s,n,m,visited,max);
	}
}
int main(){
	int m, n, k, cnt, **visited;
	char **s;
	scanf("%d%d%d", &n, &m, &k);
	s = new char*[n];
	visited = new int*[n];
	for(int i = 0 ; i < n ; i++){
		s[i] = new char[m+1];
		visited[i] = new int[m];
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%s", s[i]);
	}
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			visited[i][j] = 0;
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '.')
				cnt++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '.'){
				dfs_visit(i,j,s,n,m,visited,cnt-k);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(visited[i][j] == 0 and s[i][j] == '.'){
				s[i][j] = 'X';
			}
		}
	}
	for(int i  = 0 ; i < n ; i++){
		printf("%s\n", s[i]);
	}
	return 0;
}