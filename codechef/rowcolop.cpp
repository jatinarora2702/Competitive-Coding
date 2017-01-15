#include <cstdio>
#include <algorithm>
using namespace std;
#define N 320000
#define SN 100
typedef long long int lli;
lli row[N], col[N];
char s[SN];
int main(){
	int n, q, m, x;
	lli mr, mc, sum;
	scanf("%d%d", &n, &q);
	for(int i = 0 ; i < q ; i++){
		scanf("%s%d%d", s, &m, &x);
		m--;
		if(s[0] == 'R')
			row[m] += (lli)x;
		if(s[0] == 'C')
			col[m] += (lli)x;
	}
	mr = mc = 0;
	for(int i = 0 ; i < n ; i++){
		mr = max(mr, row[i]);
		mc = max(mc, col[i]);
	}
	sum = mr + mc;
	printf("%lld", sum);
	return 0;
}