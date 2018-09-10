#include <bits/stdc++.h>
#define FF first
#define SS second

using namespace std;

typedef pair < int, int > pii;

const int N = 5005;

pair < pii, int > a[N];
stack < int > stk;
int dp[N], s[N];

bool isvalid(pii &p1, pii &p2) {
	return p1.FF < p2.FF && p1.SS < p2.SS;
}

int main() {
	int n, i, j;
	pair < pii, int > c;
	c.SS = -1;
	scanf("%d%d%d", &n, &(c.FF.FF), &(c.FF.SS));
	for(i = 0 ; i < n ; i++) {
		a[i].SS = i;
		scanf("%d%d", &(a[i].FF.FF), &(a[i].FF.SS));
	}
	sort(a, a+n);
	dp[0] = isvalid(c.FF, a[0].FF) ? 1 : 0;
	s[0] = -1;
	for(i = 1 ; i < n ; i++) {
		dp[i] = 0;
		s[i] = -1;
		if(isvalid(c.FF, a[i].FF)) {
			for(j = 0 ; j < i ; j++) {
				if(isvalid(a[j].FF, a[i].FF) && dp[i] < dp[j]) {
					dp[i] = dp[j];
					s[i] = j;
				}
			}
			dp[i]++;
		}
	}
	j = 0;
	for(i = 1 ; i < n ; i++) {
		if(dp[j] < dp[i])
			j = i;
	}
	printf("%d\n", dp[j]);
	if(dp[j] > 0) {
		while(j >= 0) {
			stk.push(a[j].SS + 1);
			j = s[j];
		}
		while(!stk.empty()) {
			printf("%d ", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	return 0;
}