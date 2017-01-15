#include <bits/stdc++.h>
using namespace std;
#define N 50
#define FF first
#define SS second

typedef long long int lli;

map < string, int > mp;

string makepat(char *s) {
	int n, m, i;
	string pat = "0000000000000000000";
	n = strlen(s);
	m = 18;
	for(i = n-1 ; i >= 0 ; i--) {
		pat[m--] = s[i];
	}
	return pat;
}

string getpat(char *s) {
	int n, m, i;
	string pat = "0000000000000000000";
	n = strlen(s);
	m = 18;
	for(i = n-1 ; i >= 0 ; i--) {
		if((s[i]-'0') % 2 == 0)
			pat[m--] = '0';
		else
			pat[m--] = '1';
	}
	return pat;
}

int main() {
	int i, t, ans;
	char ch, s[N];
	string pat;
	scanf("%d", &t);
	mp.clear();
	for(i = 0 ; i < t ; i++) {
		getchar();
		scanf("%c", &ch);
		scanf("%s", s);
		if(ch == '+') {
			pat = getpat(s);
			// cout << "pat:" << pat << endl;
			mp[pat]++;
		}
		else if(ch == '-') {
			pat = getpat(s);
			mp[pat]--;
			// cout << "patd:" << pat << endl;
			if(mp[pat] == 0) {
				mp.erase(pat);
			}
		}
		else if(ch == '?') {
			pat = makepat(s);
			// cout << "qpat:" << pat << endl;
			if(mp.find(pat) != mp.end()) {
				ans = mp[pat];
			}
			else {
				ans = 0;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}