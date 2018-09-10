#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;

map < char, int > makemap(string s) {
	map < char, int > mp;
	mp.clear();
	for(int i = 0 ; i < s.length() ; i++) {
		mp[s[i]]++;
	}
	return mp;
}

int main() {
	int i, j, cnt;
	string t, p;
	map < char, int > mpp, mpt;
	map < char, int > :: iterator it;
	cin >> t;
	p = "Bulbasaur";
	mpp = makemap(p);
	mpt = makemap(t);
	cnt = t.length();
	for(it = mpp.begin() ; it != mpp.end() ; it++) {
		cnt = min(cnt, mpt[it->FF] / it->SS);
	}
	printf("%d\n", cnt);
	return 0;
}