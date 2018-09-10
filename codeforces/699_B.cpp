#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 1005

char s[N][N];
int n, m;

int getpaxis(int f) {
	int ni, nj, i, j, p, cnt;
	p = -1;
	if(f == 0) {
		ni = n;
		nj = m;
	}
	else {
		ni = m;
		nj = n;
	}
	for(i = 0 ; i < ni ; i++) {
		cnt = 0;
		for(j = 0 ; j < nj ; j++) {
			if(f == 0 && s[i][j] == '*')
				cnt++;
			if(f != 0 && s[j][i] == '*')
				cnt++;
		}
		if(cnt > 1) {
			if(p == -1)
				p = i;
			else
				return -2;
		}
	}
	return p;
}

int getcnt() {
	int i, j, cnt;
	cnt = 0;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			if(s[i][j] == '*')
				cnt++;
		}
	}
	return cnt;
}

int main() {
	int pi, pj, i, j, cnt, f;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%s", s[i]);
	}
	cnt = getcnt();
	if(cnt < 3) {
		pi = getpaxis(0);
		pj = getpaxis(1);
		f = 1;
		if(pi == -1 && pj == -1) {
			for(i = 0 ; i < n ; i++) {
				for(j = 0 ; j < m ; j++) {
					if(s[i][j] == '*') {
						if(pi == -1)
							pi = i;
						else {
							pj = j;
							f = 0;
							break;
						}
						if(pj == -1)
							pj = j;
					}
				}
				if(f == 0)
					break;
			}
		}
	}
	else {
		pi = getpaxis(0);
		if(pi == -2){
			printf("NO\n");
			return 0;
		}
		pj = getpaxis(1);
		if(pj == -2) {
			printf("NO\n");
			return 0;
		}
		if(pi == -1 && pj == -1) {
			printf("NO\n");
			return 0;
		}
	}
	if(pi == -1) {
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				if(s[i][j] == '*' && j != pj) {
					if(pi == -1)
						pi = i;
					else {
						printf("NO\n");
						return 0;
					}
				}
			}
		}
		if(pi == -1)
			pi = 0;
	}
	if(pj == -1) {
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < m ; j++) {
				if(s[i][j] == '*' && i != pi) {
					if(pj == -1)
						pj = j;
					else {
						printf("NO\n");
						return 0;
					}
				}
			}
		}
		if(pj == -1)
			pj = 0;
	}
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			if(s[i][j] == '*' && !(i == pi || j == pj)) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n%d %d\n", pi+1, pj+1);
	return 0;
}