#include <iostream>
#include <stdio.h>
using namespace std;
/*int isvalid(char **a, int **visited, int si, int sj, int i, int j, int n, int m){
	//printf("fn[si=%d sj=%d i=%d j=%d]\n",si,sj,i,j);
	if(i >= 0 and i < n and j >= 0 and j < m and a[i][j] == a[si][sj]){
		if(visited[i][j] == 0)
			return 1;
		else if(visited[i][j] == 1)
			return 2;
	}
	return 0;
}
int dfs_visit(char **a, int **visited, int pi, int pj, int i, int j, int n, int m){
	int f, f1;
	f1 = isvalid(a,visited,pi,pj,i,j,n,m);
	if(f1 == 2)
		return 1;
	if(f1 == 1){
		visited[i][j] = 1;
		if(j+1 != pj) f = dfs_visit(a,visited,i,j,i,j+1,n,m);
		if(f == 1) return 1;
		if(i+1 != pi) f = dfs_visit(a,visited,i,j,i+1,j,n,m);
		if(f == 1) return 1;
		if(i-1 != pi) f = dfs_visit(a,visited,i,j,i-1,j,n,m);
		if(f == 1) return 1;
		if(j-1 != pj) f = dfs_visit(a,visited,i,j,i,j-1,n,m);
		if(f == 1) return 1;
		return 0;
	}
	return 0;
}*/
int G = 0;
void dfs_visit(char **g, int **v, int x,int y,int i, int j, int n, int m)
{
    if (i<0||j<0||i>=n||j>= m |g[i][j]!=g[x][y]||v[i][j]==1)return;
    if (v[i][j] ==-1){G=1;return;}
    v[i][j]=-1;
    if (x!=i+1)dfs_visit(g,v,i,j,i+1,j,n,m);
    if (x!=i-1)dfs_visit(g,v,i,j,i-1,j,n,m);
    if (y!=j+1)dfs_visit(g,v,i,j,i,j+1,n,m);
    if (y!=j-1)dfs_visit(g,v,i,j,i,j-1,n,m);
    v[i][j]=1;
}
int main(){
	int n, m, **visited, f;
	char **a;
	scanf("%d%d", &n, &m);
	a = new char*[n];
	visited = new int*[n];
	for(int i = 0 ; i < n ; i++){
		a[i] = new char[m+1];
		visited[i] = new int[m];
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%s", a[i]);
	}
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			visited[i][j] = 0;
	f = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(visited[i][j] == 0){
				dfs_visit(a,visited,i,j,i,j,n,m);
				if(G == 1)
					break;
			}
			if(G == 1)
				break;
		}
	}
	if(G == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}