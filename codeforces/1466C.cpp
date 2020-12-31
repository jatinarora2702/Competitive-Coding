#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int m = 0;
		for(int i = 1; i < s.size(); i++) {
			if (s[i] == s[i-1]) {
				s[i] = '#';
				m++;
			}
			else if (i-2 >= 0 && s[i] == s[i-2]) {
				s[i] = '#';
				m++;
			}
		}
		cout << m << "\n";
	}
	return 0;
}