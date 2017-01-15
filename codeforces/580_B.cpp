#include <bits/stdc++.h>
#define N 100005
#define ff first
#define ss second
using namespace std;
typedef long long int lli;
pair < int, int > p [N];
lli sums[N];
bool fn(pair < int, int > a, pair < int, int > b){
	if(a.ff != b.ff){
		return a.ff > b.ff;
	}
	return a.ss > b.ss;
}
int binsearch(pair < int ,int > *p, int b, int e, int x){
	int m, cnt;
	while(b <= e){
		//cout << "b=" << b << " e=" << e << endl;
		m = (b + e) / 2;
		if(p[m].ff <= x)
			e = m - 1;
		else if(p[m].ff > x)
			b = m + 1;
	}
	return b;
}
int main() {
	int n, d, x, y, z, cnt;
	lli maxm, val;
	scanf("%d%d", &n, &d);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
	}
	if(d == 0){
		cnt = 0;
		for(int i = 1 ; i < n ; i++){
			if(p[cnt].ss < p[i].ss)
				cnt = i;
		}
		maxm = (lli)p[cnt].ss;
		cout << maxm;
	}
	else{
		sort(p, p+n, fn);
		sums[n-1] = p[n-1].ss;
		for(int i = n-2 ; i >= 0;  i--){
			sums[i] = sums[i+1] + (lli)p[i].ss;
		}
		// for(int i = 0 ; i < n ; i++){
		// 	cout << "(" << p[i].ff << " " << p[i].ss << ") ";
		// }
		// cout << endl;
		// for(int i = 0 ; i < n ; i++){
		// 	cout << sums[i] << " ";
		// }
		// cout << endl;
		maxm = 0;
		for(int i = 0 ; i < n ; i++){
			z = p[i].ff;
			x = z - d;
			cnt = binsearch(p, i, n-1, x);
			// cout << "cnt=" << cnt << endl;
			if(cnt == n)
				val = sums[i];
			else
				val = sums[i] - sums[cnt];
			if(val > maxm)
				maxm = val;
		}
		cout << maxm;	
	}
	return 0;
}