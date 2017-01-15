#include <bits/stdc++.h>
#define N 5000001
using namespace std;
typedef long long int lli;
lli a[N], v, d;
int status[N];
int main() {
	int t, n, f, b, e, m, j, k;
	for(int i = 1 ; i < N ; i++)
		a[i] = (lli)i * (lli)i;
	sort(a, a+N);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(status[n] == 0){
			f = 0;
			v = (lli)n * (lli)n;
			if(n % 2 == 0)
				j = 2;
			else
				j = 1;
			for( ; j < n ; j+=2){
				d = v - a[j];
				b = 0;
				e = n - 1;
				while(b <= e){
					m = (b + e) / 2;
					if(a[m] < d){
						b = m+1;
					}
					else if(a[m] > d){
						e = m-1;
					}
					else{
						f = 1;
						break;
					}
				}
				if(f == 1){
					status[n] = 1;
					k = 2 * n;
					while(k < N){
						status[k] = 1;
						k += n;
					}
					break;
				}
			}
			if(f == 0){
				status[n] = -1;
			}
		}
		if(status[n] == -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}