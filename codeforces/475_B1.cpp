#include <iostream>
#include <stdio.h>
using namespace std;
void dfs_visit(int i, int j, int n, int m, int **visited, char **s){
	visited[i][j] = 1;
	//cout << "pp\n";
	if(s[0][i] == '>' and j+1 < m and visited[i][j+1] == 0)
		dfs_visit(i,j+1,n,m,visited,s);
	else{ 
		if(s[0][i] == '<' and j-1 >= 0 and visited[i][j-1] == 0)
			dfs_visit(i,j-1,n,m,visited,s);
	}
	if(s[1][j] == 'v' and i+1 < n and visited[i+1][j] == 0)
		dfs_visit(i+1,j,n,m,visited,s);
	else{
		if(s[1][j] == '^' and i-1 >= 0 and visited[i-1][j] == 0)
			dfs_visit(i-1,j,n,m,visited,s);
	}
}
int main() {
	int n, m, **visited, k;
	char **s;
	scanf("%d%d", &n, &m);
	visited = new int*[n];
	s = new char*[2];
	s[0] = new char[n+1];
	s[1] = new char[m+1];
	for(int i = 0 ; i < n ; i++){
		visited[i] = new int[m];
	}
	for(int i = 0 ; i < 2 ; i++)
		scanf("%s", s[i]);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			visited[i][j] = 0;
	//cout << "y\n";
	dfs_visit(0,0,n,m,visited,s);
	k = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(visited[i][j] == 0){
				k = 1;
				break;
			}
		}
		if(k == 1)
			break;
	}
	if(k == 1)
		printf("NO");
	else{
		for(int i = 0 ; i < n ; i++){
			if(s[0][i] == '<')
				s[0][i] = '>';
			else
				s[0][i] = '<';
		}
		for(int i = 0 ; i < m ; i++){
			if(s[1][i] == 'v')
				s[1][i] = '^';
			else
				s[1][i] = 'v';
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				visited[i][j] = 0;
		dfs_visit(0,0,n,m,visited,s);
		k = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(visited[i][j] == 0){
					k = 1;
					break;
				}
			}
			if(k == 1)
				break;
		}
		if(k == 1)
			printf("NO");
		else
			printf("YES");
	}
	return 0;
}