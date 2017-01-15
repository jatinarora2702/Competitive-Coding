#include <bits/stdc++.h>
#define N 5000001
using namespace std;
typedef long long int lli;
lli a[N], v, d;
int status[N];
int main() {
	int t, n, k, f, b, e, m, j;
	for(int i = 1 ; i < N ; i++)
		a[i] = (lli)i * (lli)i;
	sort(a, a+N);
	printf("yy\n");
	for(int i = 5 ; i < N ; i++){
		if(status[i] == 1)
			continue;
		v = (lli)i * (lli)i;
		if(i % 2 == 0)
			j = 2;
		else
			j = 1;
		for( ; j < i ; j+=2){
			d = v - a[j];
			b = 0;
			e = n - 1;
			while(b <= e){
				m = (b + e) / 2;
				if(a[m] < d)
					b = m+1;
				else if(a[m] > d)
					e = m-1;
				else{
					f = 1;
					break;
				}
			}
			if(f == 1)
				break;
		}
		if(f == 1){
			status[i] = 1;
			k = 2 * i;
			while(k < N){
				status[k] = 1;
				k += i;
			}
		}
	}
	printf("pp\n");
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(status[n] == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}