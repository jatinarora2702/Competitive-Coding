#include <bits/stdc++.h>
#define N 100000
#define ff first
#define ss second
using namespace std;
pair < int, int > p[N];
int main(){
	int n, k, m, *a, x, x1, x2, grp, last;
	scanf("%d%d%d", &n, &k, &m);
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		p[i] = make_pair(x, i);
	}
	sort(p, p+n);
	grp = 0;
	last = p[0].ff;
	a[p[0].ss] = grp;
	for(int i = 1 ; i < n ; i++){
		if(p[i].ff - last > k)
			grp++;
		a[p[i].ss] = grp;
		last = p[i].ff;
	}
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x1, &x2);
		x1--; x2--;
		if(a[x1] == a[x2])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}