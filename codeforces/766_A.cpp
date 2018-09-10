#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 100005

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.length() != s2.length())
		cout << max(s1.length(), s2.length()) << endl;
	else {
		for(int i = 0 ; i < s1.length() ; i++) {
			if(s1[i] != s2[i]) {
				cout << s1.length() << endl;
				return 0;
			}
		}
		printf("-1\n");
	}
	return 0;
}