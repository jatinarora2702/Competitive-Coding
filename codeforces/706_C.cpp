#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
vector < string > v;
vector < pair < string, lli > > vs, vstemp; 
int main() {
	int n, i, j;
	string str;
	lli ans;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0 ; i < n ; i++) {
		cin >> str;
		v.PB(str);
	}
	vs.PB(MP(v[0], 0));
	reverse(v[0].begin(), v[0].end());
	vs.PB(MP(v[0], a[0]));
	for(i = 1 ; i < n ; i++) {
		vstemp.clear();
		str = v[i];
		reverse(v[i].begin(), v[i].end());
		for(j = 0 ; j < vs.size() ; j++) {
			if(vs[j].FF.compare(v[i]) <= 0)
				vstemp.PB(MP(v[i], vs[j].SS + (lli)a[i]));
			if(vs[j].FF.compare(str) <= 0)
				vstemp.PB(MP(str, vs[j].SS));
		}
		vs = vstemp;
	}
	if(vs.size() == 0)
		printf("-1\n");
	else {
		ans = vs[0].SS;
		for(i = 1 ; i < vs.size() ; i++) {
			ans = min(ans, vs[i].SS);
		}
		cout << ans << "\n";
	}
	return 0;
}