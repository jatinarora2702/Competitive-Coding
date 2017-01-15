#include <iostream>
#include <stdio.h>
using namespace std;
char s[501][501];
int n, m, dx, dy, sx, sy, f;
int visited[501][501];
inline int abs(int x){
	return (x < 0) ? (-x) : x;
}
int count(int x, int y, char c){
	int cnt = 0;
	if(x+1 < n and s[x+1][y] == c) cnt++;
	if(x > 0 and s[x-1][y] == c) cnt++;
	if(y+1 < m and s[x][y+1] == c) cnt++;
	if(y > 0 and s[x][y-1] == c) cnt++;
	return cnt;
}
void dfs_visit(int x, int y){
	if(f == 1 or x >= n or y >= m or x < 0 or y < 0 or visited[x][y] == 1)
		return;
	if(x == dx and y == dy){
		f = 1;
		return;
	}
	if((x != sx or y != sy) and s[x][y] == 'X')
		return;
	//cout << "x=" << x+1 << "y=" << y+1 << "s : " << s[x][y] << endl;
	visited[x][y] = 1;
	dfs_visit(x+1, y);
	dfs_visit(x-1, y);
	dfs_visit(x, y+1);
	dfs_visit(x, y-1);
}
int main(){
	int k;
	k = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			visited[i][j] = 0;
		}
	}
	for(int i =  0 ; i < n ; i++){
		scanf("%s", s[i]);
	}
	scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
	sx--, sy--, dx--, dy--;
	f = 0;
	dfs_visit(sx, sy);
	if(f == 0)
		printf("NO");
	else{
		if(s[dx][dy] == 'X'){
			if(dx == sx and dy == sy){
				k = count(dx, dy, '.');
				if(k >= 1)
					printf("YES");
				else
					printf("NO");
			}
			else
				printf("YES");
		}
		else{
			k = count(dx, dy, '.');
			//cout << "k=" << k << endl;
			if(k >= 2)
				printf("YES");
			else if(k == 1){
				if(dx == sx and abs(sy-dy) == 1)
					printf("YES");
				else if(dy == sy and abs(sx-dx) == 1)
					printf("YES");
				else
					printf("NO");
			}
			else 
				printf("NO");
		}
	}
	return 0;
}