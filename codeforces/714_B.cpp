#include <bits/stdc++.h>
using namespace std;
#define N 100005

int a[N], b[10];

set < int > st;

int main() {
	int n, j;
	scanf("%d", &n);
	st.clear();
	for(int i = 0 ; i <  n;  i++) {
		scanf("%d", &a[i]);
		st.insert(a[i]);
	}
	if(st.size() > 3) {
		printf("NO\n");
		return 0;
	}
	if(st.size() == 3) {
		j = 0;
		for(auto it : st) {
			b[j] = it;
			j++;
		}
		sort(b, b+j);
		if(b[1] - b[0] == b[2] - b[1]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	else {
		printf("YES\n");
	}
	return 0;
}