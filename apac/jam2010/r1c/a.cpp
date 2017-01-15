#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define N 1005
using namespace std;

pair < pair < int, int >, int > p[N];
vector < int > vs[N], ve[N], vtemp;
vector < int > :: iterator it;

bool fn1(pair < pair < int, int >, int > p1, pair < pair < int, int >, int > p2) {
	return p1.FF.FF < p2.FF.FF;
}
bool fn2(pair < pair < int, int >, int > p1, pair < pair < int, int >, int > p2) {
	return p1.FF.SS < p2.FF.SS;
}
int main() {
	int t, i, s, n, h, j;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d%d", &p[i].FF.FF, &p[i].FF.SS);
			p[i].SS = i;
		}
		sort(p, p+n, fn1);
		// printf("\nsorted: ");
		// for(i = 0 ; i < n ; i++) {
		// 	printf("%d ", p[i].SS);
		// }
		// printf("\n");
		vtemp.clear();
		for(i = n-1 ; i >= 0 ; i--) {
			vs[p[i].SS] = vtemp;
			vtemp.PB(p[i].SS);
		}
		sort(p, p+n, fn2);
		// printf("\nsorted: ");
		// for(i = 0 ; i < n ; i++) {
		// 	printf("%d ", p[i].SS);
		// }
		// printf("\n");
		vtemp.clear();
		for(i = 0 ; i < n ; i++) {
			ve[p[i].SS] = vtemp;
			vtemp.PB(p[i].SS);
		}
		// printf("------------\n");
		// for(i = 0 ; i < n ; i++) {
		// 	printf("%d: ", p[i].SS);
		// 	for(j = 0 ; j < vs[p[i].SS].size() ; j++) {
		// 		printf("%d ", vs[p[i].SS][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("-----------\n");
		// for(i = 0 ; i < n ; i++) {
		// 	printf("%d: ", p[i].SS);
		// 	for(j = 0 ; j < ve[p[i].SS].size() ; j++) {
		// 		printf("%d ", ve[p[i].SS][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("--------\n");
		for(i = 0 ; i < n ; i++) {
			sort(vs[p[i].SS].begin(), vs[p[i].SS].end());
		}
		for(i = 0 ; i < n ; i++) {
			sort(ve[p[i].SS].begin(), ve[p[i].SS].end());
		}
		s = 0;
		for(i = 0 ; i < n ; i++) {
			vtemp.clear();
			vtemp.resize(N);
			it = set_intersection(vs[p[i].SS].begin(), vs[p[i].SS].end(), ve[p[i].SS].begin(), ve[p[i].SS].end(), vtemp.begin());
			vtemp.resize(it - vtemp.begin());
			// printf("i=%d| ", i);
			// for(j = 0 ; j < vtemp.size() ; j++) {
			// 	printf("%d ", vtemp[j]);
			// }
			// printf("\n");
			// printf("size=%d\n", vtemp.size());
			s += vtemp.size();
		}
		printf("Case #%d: %d\n", h, s);
	}
	return 0;
}