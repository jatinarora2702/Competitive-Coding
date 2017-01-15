#include <bits/stdc++.h>
#define N 200005
#define FF first
#define SS second
#define INF 1000000007
using namespace std;
typedef long long int lli;
int drate[N], prate[N];
pair < pair < int, pair < int, int > >, pair < int, int > > gm[N];
int main(){
	int k, s, n, m, k1, k2, f, ok1, ok2;
	lli val, s1;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &drate[i]);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &prate[i]);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &gm[i].FF.SS.FF, &gm[i].FF.SS.SS);
		gm[i].SS.FF = i;
		gm[i].FF.FF = INF;
	}
	k1 = k2 = INF;
	f = 0;
	for(int i = 0 ; i < n ; i++){
		if(drate[i] < k1 || prate[i] < k2){
			ok1 = k1;
			ok2 = k2;
			k1 = min(k1, drate[i]);
			k2 = min(k2, prate[i]);
			for(int j = 0 ; j < m ; j++){
				if(k1 < ok1 && gm[j].FF.SS.FF == 1){
					// cout << "val=" << val << endl;
					val = (lli)gm[j].FF.SS.SS * (lli)k1;
					if(val < gm[j].FF.FF){
						gm[j].FF.FF = val;
						gm[j].SS.SS = i;
					}
				}
				else if(k2 < ok2 && gm[j].FF.SS.FF == 2){
					val = (lli)gm[j].FF.SS.SS * (lli)k2;
					if(val < gm[j].FF.FF){
						gm[j].FF.FF = val;
						gm[j].SS.SS = i;
					}
				}
			}
			sort(gm, gm+m);
			// for(int j = 0 ; j < m ; j++){
			// 	printf("(%d %d %d %d %d) ", gm[j].FF.FF, gm[j].FF.SS.FF, gm[j].FF.SS.SS, gm[j].SS.FF, gm[j].SS.SS);
			// }
			// printf("\n");
			s1 = 0;
			for(int j = 0 ; j < k ; j++)
				s1 += (lli)gm[j].FF.FF;
			// cout << "s1=" << s1 << endl;
			if(s1 <= s){
				printf("%d\n", i+1);
				for(int j = 0 ; j < k ; j++){
					printf("%d %d\n", gm[j].SS.FF+1, gm[j].SS.SS+1);
				}
				f = 1;
				break;
			}
		}
	}
	if(f == 0)
		printf("-1");
	return 0;
}