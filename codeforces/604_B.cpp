#include <bits/stdc++.h>
#define N 100005
using namespace std;
int a[N];
int main() {
	int n, k, ans, s, b, e;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	ans = a[n-1];
	s = n - k;
	b = 0;
	e = 2 * s - 1;
	while(e < n && b < e){
		ans = max(ans, a[b] + a[e]);
		b++;
		e--;
	}
	printf("%d", ans);
	return 0;
}