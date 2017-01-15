#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n,m,u,v,sum, *a;
	scanf("%d%d",&n, &m);
	a = new int[n];
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&a[i]);
	}
	sum = 0;
	for(int i = 0 ; i < m ; i++ ) {
		scanf("%d%d", &u, &v);
		u--; v--;
		sum += (a[u] < a[v]) ? a[u] : a[v];
	}
	printf("%d",sum);
	return 0;
}