#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 50;
char s[N][N];
int visited[N][N];
int n, m, f;
void dfs_visit(int si, int sj, char c, int pi, int pj){
	//printf("[%d %d]\n", si+1, sj+1);
	if(si < 0 or si >= n or sj < 0 or sj >= m or s[si][sj] != c)
		return;
	//printf("%d %d\n", si+1, sj+1);
	if(visited[si][sj] == 1){
		//printf("doing.. si= %d, sj= %d, pi= %d, pj= %d\n", si+1, sj+1, pi+1, pj+1);
		f = 1;
		return;
	}
	visited[si][sj] = 1;
	if(sj+1 != pj) dfs_visit(si, sj+1, c, si, sj);
	if(f == 0 and si+1 != pi) dfs_visit(si+1,sj, c, si, sj);
	if(f == 0 and sj-1 != pj) dfs_visit(si, sj-1, c, si, sj);
	if(f == 0 and si-1 != pi) dfs_visit(si-1, sj, c, si, sj);
}
void dfs(){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			visited[i][j] = 0;
	f = 0;
	//printf("uu\n");
	for(int i = 0 ; i < n ; i++){
		//printf("qqqq\n");
		for(int j = 0 ; j < m ; j++){
			//printf("kk\n");
			if(visited[i][j] == 0){
				//printf("pp\n");
				dfs_visit(i, j, s[i][j], -1, -1);
				if(f == 1)
					break;
			}
		}
		if(f == 1)
			break;
	}
	if(f == 1)
		printf("Yes");
	else
		printf("No");
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%s", s[i]);
	}
	dfs();
	return 0;
}