#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 100005

int a[N];

int main() {
	int n, s, x, i;
	cin >> n;
	s = n;
	for(i = 0 ; i < n ; i++) {
		cin >> x;
		a[x] = 1;
		while(a[s] == 1 && s > 0) {
			cout << s << " ";
			s--;
		}
		cout << endl;
	}
	return 0;
}