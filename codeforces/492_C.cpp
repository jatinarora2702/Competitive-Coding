#include <bits/stdc++.h>
#define N 100005
#define M 1000005
#define FF first
#define SS second
#define MP make_pair
using namespace std;
typedef long long int lli;
int a[N], b[N], c[M];
pair < int, int > p[N];
bool fn(pair < int, int > p1, pair < int, int > p2){
	if(p1.SS <= p2.SS)
		return true;
	return false;
}
int main() {
	int n, r, avg, j, k, rem;
	lli his, tot, dif, cnt;
	scanf("%d%d%d", &n, &r, &avg);
	his = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &a[i], &b[i]);
		p[i] = make_pair(a[i], b[i]);
		his += (lli)a[i];
		c[b[i]]++;
	}
	tot = (lli)avg * (lli)n;
	dif = tot - his;
	
	sort(p, p+n, fn);
	j = 0;
	cnt = 0;
	while(j < n && dif > 0){
		rem = r - p[j].FF;
		k = (int)min((lli)rem, dif);
		cnt += (lli)p[j].SS * (lli)k;
		dif -= (lli)k;
		j++;
	}
	printf("%I64d", cnt);
	return 0;
}