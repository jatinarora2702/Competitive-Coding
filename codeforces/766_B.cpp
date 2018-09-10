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

int a[N];
int main() {
	int n, i, ans;
	cin >> n;
	for(i = 0 ; i < n ; i++)
		cin >> a[i];
	sort(a, a+n);
	ans = 0;
	for(i = 0 ; i < n-2 ; i++) {
		if((a[i] + a[i+1]) <= a[i+2])
			continue;
		if((a[i+1] + a[i+2]) <= a[i])
			continue;
		if((a[i] + a[i+2]) <= a[i+1])
			continue;
		ans = 1;
		break;
	}
	if(ans == 1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}