#include <iostream>
#include <stdio.h>
using namespace std;
int isvalid(char **a, int **visited,int pi, int pj, int si, int sj, int i, int j, int n, int m){
	//printf("fn[si=%d sj=%d i=%d j=%d]\n",si,sj,i,j);
	if(i >= 0 and i < n and j >= 0 and j < m and a[i][j] == a[si][sj]){
		if(visited[i][j] == 0)
			return 1;
		else if(i == pi and j == pj)
			return 0;
		else if(visited[i][j] == 1)
			return 2;
	}
	return 0;
}
int G=0;
void dfs_visit(char **a, int **visited, int pi, int pj, int i, int j, int n, int m){
	int f, f1;
	//printf("[%d %d]-[n=%d m=%d]\n",i,j,n,m);
	visited[i][j] = 1;
	f1 = isvalid(a,visited,pi,pj,i,j,i,j+1,n,m);
	//printf("1f1=%d\n",f1);
	if(f1 == 2){
		G = 1;
		return;
	}
	if(f1 == 1){
		dfs_visit(a,visited,i,j,i,j+1,n,m);
	}
	//cout << "k2\n";
	f1 = isvalid(a,visited,pi,pj,i,j,i+1,j,n,m);
	//printf("2f1=%d\n",f1);
	if(f1 == 2){
		G = 1;
		return;
	}
	if(f1 == 1){
		dfs_visit(a,visited,i,j,i+1,j,n,m);
		//printf("2f=%d\n",f);
	}
	//cout << "k3\n";
	f1 = isvalid(a,visited,pi,pj,i,j,i-1,j,n,m);
	//printf("3f1=%d\n",f1);
	if(f1 == 2){
		G = 1;
		return;
	}
	if(f1 == 1){
		dfs_visit(a,visited,i,j,i-1,j,n,m);
	}
	//cout << "k4\n";
	f1 = isvalid(a,visited,pi,pj,i,j,i,j-1,n,m);
	//printf("4f1=%d\n",f1);
	if(f1 == 2){
		G = 1;
		return;
	}
	if(f1 == 1){
		dfs_visit(a,visited,i,j,i,j-1,n,m);
		//printf("4f=%d\n",f);
	}
	//cout << "k5\n";
	//visited[i][j] = 2;
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
				dfs_visit(a,visited,-1,-1,i,j,n,m);
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