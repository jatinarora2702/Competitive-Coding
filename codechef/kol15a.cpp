#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 1005

int main() {
	int sum, t;
	scanf("%d", &t);
	string s;
	while(t--) {
		cin >> s;
		sum = 0;
		for(auto it : s) {
			if(it >= '0' && it <= '9')
				sum += (int)(it - '0');
		}
		cout << sum << endl;
	}
	return 0;
}