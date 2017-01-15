#include <iostream>
#include <cstdio>
#include <algorithm>
#define FF first
#define SS second
#define N 100005
#define MP make_pair
using namespace std;
typedef long long int lli;
lli s, x;
int ans[N], t, n, m, x1, y1;
pair < lli , int > p[N];
pair < int , int > q[N];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &m);
			for(int j = 0 ; j < m ; j++){
				scanf("%d%d", &x1, &y1);
				q[j] = MP(x1, y1);
			}
			x = 0;
			for(int j = 0 ; j < m-1 ; j++)
				x += ((lli)q[j].FF * (lli)q[j+1].SS - (lli)q[j+1].FF * (lli)q[j].SS);
			x += ((lli)q[m-1].FF * (lli)q[0].SS - (lli)q[0].FF * (lli)q[m-1].SS);
			p[i] = MP(abs(x), i);
		}
		sort(p, p+n);
		for(int i = 0 ; i < n ; i++)
			ans[p[i].SS] = i;
		for(int i = 0 ; i < n ; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}