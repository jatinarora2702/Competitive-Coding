#include <bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long int lli;
int a[N], posl[N], posr[N];
lli sl[N], sr[N];
int main() {
	int n, ml, mr, i, j;
	lli s, sp, cnt;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	s = 0LL;
	for(i = 0 ; i < n ; i++) {
		s += (lli)a[i];
		sl[i] = s;
	}
	s = 0LL;
	for(i = n-1 ; i >= 0 ; i--) {
		s += (lli)a[i];
		sr[i] = s;
	}
	// for(i = 0 ; i < n ; i++) {
	// 	cout << sl[i] << " ";
	// }
	// cout << endl;
	// for(i = 0 ; i < n ; i++) {
	// 	cout << sr[i] << " ";
	// }
	// cout << endl;
	cnt = 0LL;
	if(sl[n-1] % 3LL == 0LL) {
		sp = sl[n-1] / 3LL;
		j = 0;
		for(i = 0 ; i < n ; i++) {
			if(sl[i] == sp)
				posl[j++] = i;
		}
		ml = j;
		j = 0;
		for(i = 0 ; i < n ; i++) {
			if(sr[i] == sp)
				posr[j++] = i;
		}
		mr = j;
		// for(i = 0 ; i < ml ; i++) {
		// 	printf("%d ", posl[i]);
		// }
		// printf("\n");
		// for(i = 0 ; i < mr ; i++) {
		// 	printf("%d ", posr[i]);
		// }
		// printf("\n");
		for(i = 0 ; i < ml ; i++) {
			cnt += (lli)(mr - (upper_bound(posr, posr+mr, posl[i]+1)-posr));
		}
	}
	cout << cnt << "\n";
	return 0;
}