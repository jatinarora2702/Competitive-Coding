#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int a[10][10][10][10];
int ans[10][10];

void eval(int x, int y) {
	int dp[10][10];
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			dp[i][j] = INF;
		}
	}
	for(int i = 0; i < 10; i++) {
		dp[i][(i+x)%10] = 1;
		dp[i][(i+y)%10] = 1;
	}
	for(int k = 0; k < 10; k++) {
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			int val = (dp[i][j] == INF) ? -1 : dp[i][j];
			a[x][y][i][j] = val;
		}
	}
}

void init() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			eval(i, j);
		}
	}
}

int main() {
	string s;
	init();
	cin >> s;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j <= i; j++) {
			int v = 0;
			for(int k = 0; k < s.length() - 1; k++) {
				int x, y;
				x = s[k] - '0';
				y = s[k+1] - '0';
				if (a[i][j][x][y] == -1) {
					v = -1;
					break;
				}
				v += a[i][j][x][y] - 1;
			}
			ans[i][j] = v;
		}
	}
	for(int i = 0; i < 10; i++) {
		for(int j = i+1; j < 10; j++) {
			ans[i][j] = ans[j][i];
		}
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}