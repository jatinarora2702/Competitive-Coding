#include <bits/stdc++.h>
#define N 2005
using namespace std;

int p[N];

void preprocess(string s) {
	int i, j;
	p[0] = 0;
	j = 0;
	for(i = 1; i < s.length(); i++) {
		if(s[i] == s[j]) {
			j++;
			p[i] = j;
		}
		else if(j == 0)
			p[i] = 0;
		else {
			i--;
			j = p[j-1];
		}
	}
}

int main() {
	int t, c, i, f;
	string s, str;
	cin >> t;
	for(c = 1; c <= t; c++) {
		cin >> s;
		preprocess(s);
		f = 0;
		for(i = 0; i < s.length()-1; i++) {
			if(p[i] > 0 && p[i+1] != p[i] + 1) {
				str = s.substr(0, i+1) + s.substr(p[i]);
				f = 1;
				break;
			}
		}
		cout << "Case #" << c << ": ";
		if(f == 0)
			cout << "Impossible" << endl;
		else
			cout << str << endl;
	}
	return 0;
}