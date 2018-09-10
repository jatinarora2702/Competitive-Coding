#include <bits/stdc++.h>
#define USED -1
using namespace std;

const int N = 200005;

int a[N], b[N];

int main() {
	int n, i, j, k;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	j = 1;
	k = 0;
	for(i = 0 ; i < n ; i++) {
		if (b[a[i]] > 1 || b[a[i]] == USED) {
			while(j <= n && b[j] > 0) j++;
			if (j < a[i]) {
				k++;
				b[a[i]]--;
				a[i] = j++;
			}
			else if (b[a[i]] == USED) {
				k++;
				a[i] = j++;
			}
			else
				b[a[i]] = USED;
		}
	}
	printf("%d\n", k);
	for(i = 0 ; i < n ; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}