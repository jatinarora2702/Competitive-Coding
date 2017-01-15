#include <bits/stdc++.h>
#define ff first
#define ss second
#define N 100005
using namespace std;
typedef long long int lli;
int main() {
	int n, *a, b[N], k, l[N], r[N], *c, j, f, v, maxm, begin, end, mid,countt[100001],flagg=1,low;
	pair < int, int > *p;
	lli cnt;
	memset(countt,0,sizeof(countt));
	scanf("%d%d", &n, &k);
	a = new int[n];
	c = new int[n];
	p = new pair < int, int > [n];
	for(int i = 0 ; i < N ; i++){
		b[i] = l[i] = r[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		countt[a[i]]++;
		p[i] = make_pair(a[i], i);
		b[a[i]] = 1;
	}
	for(int i=0;i<n;i++)
		if(countt[a[i]] > 100)
			flagg=0;

	if((k!=0 && n > 1000) || (k==0 && flagg==1)){
	sort(p, p+n);
	for(int i = 0 ; i < n ; i++){
		l[p[i].ff] = i;
		j = i+1;
		while(p[j].ff == p[i].ff)
			j++;
		j--;
		r[p[i].ff] = j;
		i = j;
	}
	// for(int i = 0 ; i < n ; i++){
	// 	printf("(%d %d) ", p[i].ff, p[i].ss);
	// }
	// printf("\nppp\n");
	// for(int i = 0 ; i < 10; i++){
	// 	printf("(%d %d)", l[i], r[i]);
	// }
	// printf("\n");
	for(int i = n-1 ; i >= 0 ; i--){
		c[i] = 0;
		if(a[i] > k){
			f = 0;
			v = a[i] * f + k;
			while(true){
				if(b[v] != -1){
					begin = l[v];
					end = r[v];
					// printf("in\n");
					while(begin <= end){
						mid = (begin + end) / 2;
						// printf("kk\n");
						if(p[mid].ss >= i)
							end = mid-1;
						else{
							c[i] = max(c[i], p[mid].ss+1);
							begin = mid+1;
						}
					}
				}
				f++;
				v = a[i] * f + k;
				// printf("%d\n", c[i]);
				if(v > 100000)
					break;
			}	
		}
		// printf("------------------------------------\n");
	}
	maxm = 0;
	cnt = 1;
	// printf("\nkakaka\n");
	// for(int i = 0 ; i < n; i++)
	// 	printf("%d ", c[i]);
	// printf("\n");
	for(int i = 1 ; i < n ; i++){
		maxm = max(maxm, c[i]);
		cnt += (lli)(i-maxm+1);
	}
	printf("%lld", cnt);
	return 0;}
	else
	{
		b[0] = 0;
	cnt = 1;
	for(int i = 1 ; i < n ; i++){
		low = 0;
		j = i-1;
		cnt++;
		while(j >= low){
			if(a[j] % a[i] == k){
				b[i] = j+1;
				break;
			}
			cnt++;
			low = max(low, b[j]);
			j--;
		}
		if(j < low)
			b[i] = low;
	}
	printf("%lld", cnt);
	return 0;
	}
}