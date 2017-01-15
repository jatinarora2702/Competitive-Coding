#include <bits/stdc++.h>
#define MP make_pair
#define FF first
#define SS second
#define N 105
#define M 1005
using namespace std;

const int INF = 1e9+7;

int p[N], h[N], v[M], a[N];
priority_queue <pair <int, int>, vector <pair <int, int> >, less <pair <int, int> > > pq;
int d[N][M]; 
int main() {
	int t, n, m, q, h1, maxm, minm, i, j, k, f;
	pair < int, int > pr;
	scanf("%d", &t);
	h1 = 0;
	while(t--) {
		h1++;
		while(!pq.empty())
			pq.pop();
		scanf("%d%d%d", &n, &m, &q);
		for(i = 0 ; i < m ; i++) {
			scanf("%d", &v[i]);
		}
		for(i = 0 ; i < n ; i++) {
			scanf("%d%d", &p[i], &h[i]);
		}
		for(i = 0 ; i < n ; i++) {
			if(p[i] < 0) {
				maxm = -INF;
				for(j = 0 ; j < m ; j++) {
					if(h[i]+j < m)
						maxm = max(maxm, v[h[i]+j]);
					if(h[i]-j >= 0)
						maxm = max(maxm, v[h[i]-j]);
					// printf("i=%d|j=%d|maxm=%d\n", i, j, maxm);
					if(maxm <= 0)
						d[i][j] = INF;
					else
						d[i][j] = (int)((-p[i] / (1.0 * maxm)) + 0.5);
				}
			}
			else {
				minm = INF;
				for(j = 0 ; j < m ; j++) {
					if(h[i]+j < m)
						minm = min(minm, v[h[i]+j]);
					if(h[i]-j >= 0)
						minm = min(minm, v[h[i]-j]);
					// printf("i=%d|j=%d|minm=%d\n", i, j, minm);
					if(minm >= 0)
						d[i][j] = INF;
					else
						d[i][j] = (int)((-p[i] / (1.0 * minm)) + 0.5);				
				}
			}
		}
		f = 1;
		// printf("\n");
		for(i = 0 ; i < n ; i++) {
			pq.push(MP(d[i][0], i));
			// printf("[%d, %LF]", i, d[i][0]);
			a[i] = 0;
		}
		// printf("\n");
		while(f == 1 && q > 0) {
			f = 0;
			pr = pq.top();
			pq.pop();
			// printf("(%d, %LF)\n", pr.SS, pr.FF);
			k = 0;
			for(i = a[pr.SS]+1 ; i < m ; i++) {
				k++;
				if(k > q)
					break;
				if(d[pr.SS][i] != d[pr.SS][a[pr.SS]]) {
					pr.FF = d[pr.SS][i];
					q -= k;
					f = 1;
					a[pr.SS] = i;
					// printf("made:(%LF, %d)\n", pr.FF, pr.SS);
					pq.push(pr);
					break;
				}
			}
		}
		pr = pq.top();
		// printf("final:(%d, %d)\n", (int)ceil(pr.FF), pr.SS);
		if(pr.FF != INF)
			printf("Case #%d: %d\n", h1, pr.FF);
		else
			printf("Case #%d: IMPOSSIBLE\n", h1);
	}
	return 0;
}