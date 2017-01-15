#include <bits/stdc++.h>
using namespace std;

#define N 305

char board[N][N], visited[N][N];
int a[N][N], n;

void dfs_visit(int si, int sj);

int isvalid(int xi, int xj) {
    if(xi >= 0 && xi < n && xj >= 0 && xj < n && board[xi][xj] == '*')
        return 1;
    return 0;
}

void getnums() {
    int i, j;
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < n ; j++) {
            if(board[i][j] == '*') {
                a[i][j] = -1;
                continue;
            }
            a[i][j] = isvalid(i+1, j+1);
            a[i][j] += isvalid(i+1, j);
            a[i][j] += isvalid(i+1, j-1);
            a[i][j] += isvalid(i, j+1);
            a[i][j] += isvalid(i, j-1);
            a[i][j] += isvalid(i-1, j+1);
            a[i][j] += isvalid(i-1, j);
            a[i][j] += isvalid(i-1, j-1);
        }
    }
}

void expandon(int si, int sj) {
    if(si >= 0 && si < n && sj >= 0 && sj < n && visited[si][sj] == 0)
        dfs_visit(si, sj);
}

void dfs_visit(int si, int sj) {
    visited[si][sj] = 1;
    if(a[si][sj] == 0) {
        expandon(si+1, sj+1);
        expandon(si+1, sj);
        expandon(si+1, sj-1);
        expandon(si, sj+1);
        expandon(si, sj-1);
        expandon(si-1, sj+1);
        expandon(si-1, sj);
        expandon(si-1, sj-1);
    }
}

int getans() {
    int i, j, cnt;
    cnt = 0;
	memset(visited, 0, sizeof(visited));
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < n ; j++) {
            if(visited[i][j] == 0 && a[i][j] == 0) {
                cnt++;
    			dfs_visit(i, j);
            }
        }
    }
    for(i = 0 ; i < n ; i++) {
    	for(j = 0 ; j < n ; j++) {
    		if(visited[i][j] == 0 && a[i][j] > 0) {
    			cnt++;
    		}
    	}
    }
    return cnt;
}

int main() {
    int t, h, i, j, ans;
    scanf("%d", &t);
    h = 0;
    while(t--) {
        h++;
        scanf("%d", &n);
        for(i = 0 ; i < n ; i++) {
            scanf("%s", board[i]);
        }
        getnums();
        ans = getans();
        printf("Case #%d: %d\n", h, ans);
    }
    return 0;
}
