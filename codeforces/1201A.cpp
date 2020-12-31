#include <bits/stdc++.h>
#define N 1005

using namespace std;

string s[N];
int arr[N][5], a[N];

int main() {
	int n, m, i, j;
	long long score;
	cin >> n >> m;
	for(i = 0; i < n; i++) {
		cin >> s[i];
		for(j = 0; j < m; j++) {
			arr[j][s[i][j]-'A']++;
		}
	}
	for(i = 0; i < m; i++) {
		cin >> a[i];
	}
	score = 0LL;
	for(i = 0; i < m; i++) {
		score += (long long)(*max_element(arr[i], arr[i] + 5)) * (long long)a[i];
	}
	cout << score << "\n";
	return 0;
}