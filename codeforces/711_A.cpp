#include <bits/stdc++.h>
#define PB push_back
using namespace std;

vector < string > vs;
int main() {
	int n, i, f;
	f = 0;
	string s;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		if(s[0] == 'O' && s[1] == 'O' && f == 0) {
			f = 1;
			s[0] = '+';
			s[1] = '+';
		}
		if(s[3] == 'O' && s[4] == 'O' && f == 0) {
			f = 1;
			s[3] = '+';
			s[4] = '+';
		}
		vs.PB(s);
	}
	if(f == 1) {
		printf("YES\n");
		for(i = 0 ; i < vs.size() ; i++) {
			cout << vs[i] << endl;
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}