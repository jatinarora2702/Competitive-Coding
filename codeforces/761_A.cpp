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
	int a, b;
	cin >> a >> b;
	if(a == 0 && b == 0)
		printf("NO\n");
	else {
		if(abs(a - b) <= 1) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}