#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		cnt = 0;
		m = 0;
		ls = 0;
		while(cnt < n+1) {
			if(cnt % 2 == 0) {
				m++;
				ls += m;
				if(ls > n) {
					ls = n;
				}
				
			}
			else {

			}
		}
	}
}