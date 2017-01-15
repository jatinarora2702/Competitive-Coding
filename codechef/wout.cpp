#include <iostream>
#include <cstdio>
using namespace std;
void clear(int *a, int x, int y){
	for(int i = x ; i <= y ; i++)
		a[i]--;
}
int getmin(int *a, int n, int h){
	int minm, s;
	s = 0;
	for(int i = 0 ; i < h ; i++)
		s += a[i];
	minm = s;
	for(int i = h ; i < n ; i++){
		s += (a[i]-a[i-h]);
		if(s < minm)
			minm = s;
	}
	return minm;
}
int main() {
	int t, *a, n, h, minm, x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &h);
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			a[i] = n;
		for(int i = 0 ; i < n ; i++){
			scanf("%d%d", &x, &y);
			clear(a, x, y);
		}
		minm = getmin(a, n, h);
		printf("%d\n", minm);
	}
	return 0;
}