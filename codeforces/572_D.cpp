#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int *a, *b, n, k, j;
	lli s;
	scanf("%d%d", &n, &k);
	a = new int[n];
	b = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a, a+n);
	s = 0;
	j = 0;
	for(int i = 0 ; i < n-k ; i++){
		if(j+1 >= n)
			break;
		s += (lli)(a[j+1] - a[j]);
		j += 2;
	}
	cout << s;
	return 0;
}