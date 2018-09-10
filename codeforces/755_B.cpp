#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

int scount[2][26], vocab[2][26][26];

int getmin(int f, int c) {
	int minm, i, ansi;
	minm = INF;
	ansi = -1;
	for(i = 0 ; i < 26 ; i++) {
		if(vocab[f][c][i] > 0 && minm > scount[f^1][i]) {
			minm = scount[f^1][i];
			ansi = i;
		}
	}
	return ansi;
}

int main() {
	int n, m, i, j, k, f, minm, c, ans;
	string s;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		j = s.length()-1;
		if(s[0] == 'w' && s[1] == 'j')
			printf("%c ", s[j]);
		scount[0][s[0]-'a']++;
		vocab[0][s[0]-'a'][s[j]-'a']++;
	}
	for(i = 0 ; i < m ; i++) {
		cin >> s;
		j = s.length()-1;
		scount[1][s[0]-'a']++;
		vocab[1][s[0]-'a'][s[j]-'a']++;
	}
	minm = INF;
	c = -1;
	for(i = 0 ; i < 26 ; i++) {
		if(scount[0][i] > 0) {
			if(c == -1)
				c = i;
			k = getmin(0, i);
			if(minm > scount[1][k]) {
				minm = scount[1][k];
				c = i;
			}
		}
	}
	f = 0;
	ans = -1;
	while(1) {
		if(scount[f][c] == 0) {
			ans = f^1;
			break;
		}
		k = getmin(f, c);
		scount[f][c]--;
		vocab[f][c][k]--;
		c = k;
		f ^= 1;
	}
	if(ans == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}