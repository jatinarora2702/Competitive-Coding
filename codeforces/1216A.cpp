#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	string s;
	cin >> n >> s;
	m = 0;
	for(int i = 0; i < s.length()-1; i+=2) {
		if(s[i] == s[i+1]) {
			m++;
			s[i+1] = 'a' + ((s[i] - 'a') ^ 1);
		}
	}
	cout << m << "\n" << s << "\n";
	return 0;
}