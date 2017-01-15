#include <bits/stdc++.h>
#define N 105
#define ff first
#define ss second
using namespace std;
pair < int, int > p[N];
bool cmp(pair < int, int > a, pair < int, int > b){
	if(a.ff == b.ff)
		return a.ss > b.ss;
	return a.ff > b.ff;
}
int main() {
	int n, *a;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		p[i] = make_pair(a[i], i);
	}
	int cnt = 0;
	while(true){
		sort(p, p+n, cmp);
		if(p[0].ss == 0)
			break;
		int k = 1;
		if((p[0].ff - p[1].ff + 1) / 2 != 0)
			k = (p[0].ff - p[1].ff + 1) / 2;
		cnt += k;
		p[0].ff -= k;
		for(int i = 0 ; i < n ; i++){
			if(p[i].ss == 0){
				p[i].ff += k;
				break;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}