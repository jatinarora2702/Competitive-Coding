#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9;

int a[N];
char b[N];

int main() {
	int n, i, l, r, t;
	l = -INF;
	r = INF;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%s", b);
	for(i = 4 ; i < n ; i++) {
		if(b[i] == '0') {
			if(b[i] != b[i-1]) {
				if(b[i-1] == '1' && b[i-2] == '1' && b[i-3] == '1' && b[i-4] == '1') {
					t = min(a[i], a[i-1]);
					t = min(t, a[i-2]);
					t = min(t, a[i-3]);
					t = min(t, a[i-4]);
					if(t <= r) {
						r = t-1;
					}
				} 
			}
		}
		else {
			if(b[i] != b[i-1]) {
				if(b[i-1] == '0' && b[i-2] == '0' && b[i-3] == '0' && b[i-4] == '0') {
					t = max(a[i], a[i-1]);
					t = max(t, a[i-2]);
					t = max(t, a[i-3]);
					t = max(t, a[i-4]);
					if(t >= l) {
						l = t+1;
					}
				} 
			}
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}