#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define N 105
using namespace std;
typedef long long int lli;
const lli INF = 1e16;
int p[N];
lli k[N];
pair < lli, lli > pans, ptemp;
int main() {
	int t, n, h, i;
	lli temp;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		printf("Case #%d: ", h);
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d%lld", &p[i], &k[i]);
		}
		if(p[n-1] == 100) {
			printf("%lld\n", k[n-1]);
		}
		else {
			pans = MP(0, INF);
			for(i = 0 ; i < n ; i++) {
				temp = 100LL * k[i];
				if(p[i] > 0) {
					ptemp.SS = temp / (lli)p[i];
					if(temp % (lli)p[i] != 0LL)
						ptemp.SS++;
				}
				else {
					ptemp.SS = INF;
				}
				ptemp.FF = temp / (lli)(p[i] + 1);
				ptemp.FF++;
				printf("(%lld, %lld) | (%lld, %lld)\n", pans.FF, pans.SS, ptemp.FF, ptemp.SS);
				pans.FF = max(pans.FF, ptemp.FF);
				pans.SS = min(pans.SS, ptemp.SS);
			}
			printf("(%lld, %lld)\n", pans.FF, pans.SS);
			if(pans.SS == pans.FF){
				printf("%lld\n", pans.SS);
			}
			else
				printf("-1\n");
		}
	}
}