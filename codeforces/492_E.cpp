#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int x[N], y[N], a[N], grpcnt[N];
int main() {
	int n, m, dx, dy, maxm, xc;
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	for(int i = 0 ; i < m ; i++)
		scanf("%d%d", &x[i], &y[i]);
	a[0] = 0;
	xc = 0;
	for(int i = 1 ; i < n ; i++){
		a[(xc+dx)%n] = (a[xc]+dy)%n;
		xc = (xc+dx)%n;
	}
	for(int i = 0 ; i < m ; i++)
		grpcnt[(y[i]-a[x[i]]+n)%n]++;
	maxm = grpcnt[0];
	xc = 0;
	for(int i = 1 ; i < n ; i++){
		if(grpcnt[i] > maxm){
			maxm = grpcnt[i];
			xc = i;
		}
	}
	printf("0 %d", xc);
	return 0;
}