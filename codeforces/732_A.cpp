#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, r, t, 	i;
	scanf("%d%d", &k, &r);
	for(i = 0 ; i < 10 ; i++) {
		t = (k * (i+1)) % 10;
		if(t == r || t == 0) {
			printf("%d\n", i+1);
			return 0;
		}
	}
	return 0;
}