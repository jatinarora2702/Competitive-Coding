#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 3005
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
pii p;
priority_queue < pii, vector < pii >, less < pii > > pq;
vector < int > vh[N], vv[N];
int a[N], b[N], mat[N][N];
int main() {
	int t, n, k, c, x, h, i, j;
	lli s;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d%d%d", &n, &k, &c, &x);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &b[i]);
		}
		for(i = 0 ; i < n ; i++) {
			for(j = 0 ; j < n ; j++) {
				mat[i][j] = ((i+1)*a[i] + (j+1)*b[j] + c) % x;
			}
		}
		for(i = 0 ; i < n ; i++) {
			vh[i].clear();
			while(!pq.empty())
				pq.pop();
			for(j = 0 ; j < k-1 ; j++) {
				pq.push(MP(mat[i][j], j));
			}
			for(j = k-1 ; j < n ; j++) {
				pq.push(MP(mat[i][j], j));
				while(!pq.empty()) {
					p = pq.top();
					pq.pop();
					if(p.SS >= j-(k-1)) {
						pq.push(p);
						break;
					}
				}
				vh[i].PB(p.FF);
			}
		}
		s = 0LL;
		for(j = 0 ; j < n-k+1 ; j++) {
			vv[j].clear();
			while(!pq.empty())
				pq.pop();
			for(i = 0 ; i < k-1 ; i++) {
				pq.push(MP(vh[i][j], i));
			}
			for(i = k-1 ; i < n ; i++) {
				pq.push(MP(vh[i][j], i));
				while(!pq.empty()) {
					p = pq.top();
					pq.pop();
					if(p.SS >= i-(k-1)) {
						pq.push(p);
						break;
					}
				}
				vv[j].PB(p.FF);
				s += (lli)p.FF;
			}
		}
		// printf("mat:\n");
		// for(i = 0 ; i < n ; i++) {
		// 	for(j = 0 ; j < n ; j++) {
		// 		printf("%d ", mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		// printf("vh:\n");
		// for(i = 0 ; i < n ; i++) {
		// 	for(j = 0 ; j < vh[i].size() ; j++) {
		// 		printf("%d ", vh[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		// printf("vv:\n");
		// for(j = 0 ; j < n-k+1 ; j++) {
		// 	for(i = 0 ; i < vv[j].size() ; i++) {
		// 		printf("%d ", vv[j][i]);
		// 	}
		// 	printf("\n");
		// }
		printf("Case #%d: %lld\n", h, s);
	}
	return 0;
}