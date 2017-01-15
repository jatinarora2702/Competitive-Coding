#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, s, v;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		s = 0;
		for(int i = 1 ; i <= n ; i+=2){
			v = (n+1-i) * i;
			if(v % 2 != 0)
				s ^= i;
		}
		printf("%d\n", s);
	}
	return 0;
}