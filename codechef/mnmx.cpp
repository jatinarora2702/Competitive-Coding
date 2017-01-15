#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int t, n, *a, minm;
	lli s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &a[i]);
		minm = a[0];
		for(int i =0  ; i < n ; i++)
			if(a[i] < minm)
				minm = a[i];
		s = (lli)minm * (lli)(n-1);
		cout << s << "\n";
	}
	return 0;
}