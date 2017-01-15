#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1005
using namespace std;
typedef long long int lli;
const int MOD = 1e9+7;
char a[N][N];
int visited[N][N], cnt, n, m, b[N][N], c[N][N];
map < int, int > mp;
set < int > sets;
set < int > :: iterator it;
void dfs_visit(int ci, int cj, int pi, int pj, int id){
	visited[ci][cj] = 1;
	b[ci][cj] = id;
	cnt++;
	int ni, nj;
	ni = ci+1;
	nj = cj;
	if(ni >= 0 && ni <= n && nj >= 0 && nj <= m && a[ni][nj] == '.' && visited[ni][nj] == 0 && !(ni == pi && nj == pj)){
		dfs_visit(ni, nj, ci, cj, id);
	}
	ni = ci-1;
	nj = cj;
	if(ni >= 0 && ni <= n && nj >= 0 && nj <= m && a[ni][nj] == '.' && visited[ni][nj] == 0 && !(ni == pi && nj == pj)){
		dfs_visit(ni, nj, ci, cj, id);
	}
	ni = ci;
	nj = cj+1;
	if(ni >= 0 && ni <= n && nj >= 0 && nj <= m && a[ni][nj] == '.' && visited[ni][nj] == 0 && !(ni == pi && nj == pj)){
		dfs_visit(ni, nj, ci, cj, id);
	}
	ni = ci;
	nj = cj-1;
	if(ni >= 0 && ni <= n && nj >= 0 && nj <= m && a[ni][nj] == '.' && visited[ni][nj] == 0 && !(ni == pi && nj == pj)){
		dfs_visit(ni, nj, ci, cj, id);
	}
}
void dfs(){
	int id = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[i][j] == '.' && visited[i][j] == 0){
				id++;
				cnt = 0;
				dfs_visit(i, j, -1, -1, id);
				mp[id] = cnt;
			}
		}
	}
}
int main(){
	int xi, xj, val;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf(" %s", a[i]);
	}
	dfs();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[i][j] == '*'){
				sets.clear();
				xi = i+1;
				xj = j;
				if(xi >= 0 && xi < n && xj >= 0 && xj < m && a[xi][xj] == '.'){
					sets.insert(b[xi][xj]);
				}
				xi = i-1;
				xj = j;
				if(xi >= 0 && xi < n && xj >= 0 && xj < m && a[xi][xj] == '.'){
					sets.insert(b[xi][xj]);
				}
				xi = i;
				xj = j+1;
				if(xi >= 0 && xi < n && xj >= 0 && xj < m && a[xi][xj] == '.'){
					sets.insert(b[xi][xj]);
				}
				xi = i;
				xj = j-1;
				if(xi >= 0 && xi < n && xj >= 0 && xj < m && a[xi][xj] == '.'){
					sets.insert(b[xi][xj]);
				}
				val = 1;
				for(it = sets.begin() ; it != sets.end() ; it++){
					val += mp[*it];
				}
				val %= 10;
				a[i][j] = val + '0'; 
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		printf("%s\n", a[i]);
	}
	return 0;
}