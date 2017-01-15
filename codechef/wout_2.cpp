#include <iostream>
#include <cstdio>
using namespace std;
long long getmin(long long *a, long long n, long long h){
	long long s, minm;
	s = 0;
	for(long long i = 0 ; i < h ; i++)
		s += a[i];
	minm = s;
	for(long long i = h ; i < n ; i++){
		s += (a[i]-a[i-h]);
		if(s < minm)
			minm = s;
	}
	return minm;
}
int main() {
	long long t, n, h, *a, x, y;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &n, &h);
		a = new long long[n];
		for(long long i = 0 ; i < n ; i++)
			a[i] = 0;
		for(long long i = 0 ; i < n ; i++){
			scanf("%lld %lld", &x, &y);
			a[x]++;
			if(y+1 < n)
				a[y+1]--;
		}
		for(long long i = 1 ; i < n ; i++)
			a[i] += a[i-1];
		for(long long i = 0  ; i < n;  i++)
			a[i] = n - a[i];
		printf("%lld\n", getmin(a, n, h));
	}
	return 0;
}