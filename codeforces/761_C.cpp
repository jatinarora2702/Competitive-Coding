#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 100

int cost[3][N];
string s[N];

bool isspecial(char c) {
	if(c == '#' || c == '*' || c == '&')
		return true;
	return false;
}

bool ischar(char c) {
	if(c >= 'a' && c <= 'z')
		return true;
	return false;
}

bool isdig(char c) {
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

int main() {
	int n, m, i, j, k;
	lli minm;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++)
		cin >> s[i];
	for(i = 0 ; i < n ; i++) {
		cost[0][i] = cost[1][i] = cost[2][i] = INF;
		for(j = 0 ; j < m ; j++) {
			if(isspecial(s[i][j]))
				cost[2][i] = min(cost[2][i], j);
			else if(ischar(s[i][j]))
				cost[1][i] = min(cost[1][i], j);
			else if(isdig(s[i][j]))
				cost[0][i] = min(cost[0][i], j);
		}
		for(j = m-1 ; j >= 0 ; j--) {
			if(isspecial(s[i][j]))
				cost[2][i] = min(cost[2][i], m-j);
			else if(ischar(s[i][j]))
				cost[1][i] = min(cost[1][i], m-j);
			else if(isdig(s[i][j]))
				cost[0][i] = min(cost[0][i], m-j);
		}
	}
	// for(i = 0 ; i < n ; i++) {
	// 	for(j = 0 ; j < 3 ; j++) {
	// 		printf("%d ", cost[j][i]);
	// 	}
	// 	printf("\n");
	// }
	minm = INF;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			for(k = 0 ; k < n ; k++) {
				if(i != j && j != k && i != k) {
					minm = min(minm, (lli)cost[0][i] + (lli)cost[1][j] + (lli)cost[2][k]);
					minm = min(minm, (lli)cost[0][i] + (lli)cost[2][j] + (lli)cost[1][k]);
					minm = min(minm, (lli)cost[1][i] + (lli)cost[0][j] + (lli)cost[2][k]);
					minm = min(minm, (lli)cost[1][i] + (lli)cost[2][j] + (lli)cost[0][k]);
					minm = min(minm, (lli)cost[2][i] + (lli)cost[1][j] + (lli)cost[0][k]);
					minm = min(minm, (lli)cost[2][i] + (lli)cost[0][j] + (lli)cost[1][k]);
				}
			}
		}
	}
	cout << minm << endl;
	return 0;	
}