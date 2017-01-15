#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int cont = 1;
void dfs_visit(char **s, int sx, int sy, int **visited, int n, int m, int fx, int fy, int px, int py){
	//cout << "sx=" << sx << " sy=" << sy << " px=" << px << " py=" << py << endl;
	if(sx == fx and sy == fy and px != -1 and py != -1){
		visited[sx][sy] = 2;
		cont = 0;
		return;
	}
	if(visited[sx][sy] == 1 or (s[sx][sy] == 'X' and px != -1 and py != -1))
		return;
	visited[sx][sy] = 1;
	s[sx][sy] = 'X';
	if(sx+1 < n and sx+1 != px and cont)
		dfs_visit(s, sx+1, sy, visited, n, m, fx, fy, sx, sy);
	if(sx-1 >= 0 and sx-1 != px and cont)
		dfs_visit(s, sx-1, sy, visited, n, m, fx, fy, sx, sy);
	if(sy+1 < m and sy+1 != py and cont)
		dfs_visit(s, sx, sy+1, visited, n, m, fx, fy, sx, sy);
	if(sy-1 >= 0 and sy-1 != py and cont)
		dfs_visit(s, sx, sy-1, visited, n, m, fx, fy, sx, sy);
}
int dfs(char **s, int n, int m, int sx, int sy, int fx, int fy){
	int f = 0;
	char **s1 = new char*[n];
	for(int i = 0 ; i < n ; i++){
		s1[i] = new  char[m+1];
		for(int j = 0 ; j <= m ; j++){
			s1[i][j] = s[i][j];
		}
	}
	int **visited = new int*[n];
	for(int i = 0 ; i < n ; i++)
		visited[i] = new int[m];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			visited[i][j] = 0;
	if(s[fx][fy] == 'X'){
		//cout << "kk\n";
		if(sx == fx and sy == fy){
			if(fx+1 < n and s[fx+1][fy] == '.') f = 1;
			else if(fx-1 >= 0 and s[fx-1][fy] == '.') f = 1;
			else if(fy+1 < m and s[fx][fy+1] == '.') f = 1;
			else if(fy-1 >= 0 and s[fx][fy-1] == '.') f = 1;
			else f = 0;
			return f;
		}
		dfs_visit(s1, sx, sy, visited, n, m, fx, fy, -1, -1);
		if(visited[fx][fy] == 2)
			return 1;
		else
			return 0;
	}
	else{
		//cout << "tt\n";

		dfs_visit(s1, sx, sy, visited, n, m, fx, fy, -1, -1);
		if(visited[fx][fy] == 2){
			//cout << "ipipi\n";
			f = 0;
			if(fx+1 < n and s[fx+1][fy] == '.') f++;
			if(fx-1 >= 0 and s[fx-1][fy] == '.') f++;
			if(fy+1 < m and s[fx][fy+1] == '.') f++;
			if(fy-1 >= 0 and s[fx][fy-1] == '.') f++;
			//cout << "f=" << f << endl;
			if(f == 1 and (abs(sx-fx)+abs(sy-fy)) == 1)
				return 1;
			if(f >= 2)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}
int main(){
	int n, m, sx, sy, fx ,fy, f;
	char **s;
	scanf("%d%d", &n, &m);
	s = new char*[n];
	for(int i = 0 ; i < n ; i++){
		s[i] = new char[m+1];
		scanf("%s", s[i]);
	}
	scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
	sx--; sy--; fx--; fy--;
	f = dfs(s, n, m, sx, sy, fx, fy);
	if(f == 0)
		printf("NO");
	else
		printf("YES");
	return 0;
}