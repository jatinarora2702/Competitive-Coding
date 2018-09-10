#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 200

int d[N], d1[N], d2[N];
int main() {
	int i, n, l, f, ans, j;
	scanf("%d%d", &n, &l);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	
	for(i = 0 ; i < n-1 ; i++)
		d1[i] = d[i+1] - d[i];
	d1[n-1] = l - d[n-1] + d[0];
	
	for(i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	
	for(i = 0 ; i < n-1 ; i++)
		d2[i] = d[i+1] - d[i];
	d2[n-1] = l - d[n-1] + d[0];
	
	// printf("d1: ");
	// for(i = 0 ; i < n ; i++)
	// 	printf("%d ", d1[i]);
	// printf("\n");

	// printf("d2: ");
	// for(i = 0 ; i < n ; i++)
	// 	printf("%d ", d2[i]);
	// printf("\n");

	ans = 0;
	for(i = 0 ; i < n ; i++) {
		j = 0;
		f = 1;
		while(j < n) {
			if(d1[i] != d2[j])
				f = 0;
			j++;
			i = (i+1) % n;
		}
		if(f == 1) {
			ans = 1;
			break;
		}
	}
	if(ans == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}