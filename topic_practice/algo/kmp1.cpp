#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s) {
	int n = s.size();
	vector<int> p(n);
	p[0] = -1;
	int i = 1;
	int j = 0;
	while(i < n) {
		if (s[i] == s[j]) {
			p[i] = j;
			i++;
			j++;
		}
		else {
			if (j == 0) {
				p[i] = -1;
				i++;
			}
			else {
				j = p[j-1] + 1;
			}
		}
	}
	return p;
}

vector<int> match(string s, string t, vector<int>& p) {
	int n = s.size();
	int m = t.size();
	vector<int> ans;
	int i, j;
	i = j = 0;
	while(j < m) {
		if (s[i] == t[j]) {
			i++;
			j++;
			if (i == n) {
				i = p[i-1] + 1;
				ans.push_back(j-n);
			}
		}
		else {
			if (i == 0) {
				j++;
			}
			else {
				i = p[i-1] + 1;
			}
		}
	}
	return ans;
}

int main() {
	string s;
	getline(cin, s);	// smaller string
	vector<int> p = prefix(s);
	cout << "string s: [" << s << "]\n";
	cout << "prefix: ";
	for(int i = 0; i < p.size(); i++) {
		cout << p[i] << " ";
	}
	cout << "\n";
	string t;
	getline(cin, t);	// bigger string in which we have to find the smaller string
	cout << "string t: [" << t << "]\n";
	vector<int> ans = match(s, t, p);
	
	cout << "matches: ";
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}