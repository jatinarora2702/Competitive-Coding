#include <bits/stdc++.h>
#define N 200005
#define PB push_back
using namespace std;
typedef long long int lli;
const int MOD = 1e9+7;
int p[N];
vector < int > v, vcnt, vp;
int getp(int x, lli y){
	if(y == 0)
		return 1;
	int val = getp(x, y / (lli)2);
	lli t1 = (lli)val * (lli)val;
	t1 %= (lli)MOD;
	if(y % (lli)2 == 1){
		t1 *= (lli)x;
		t1 %= (lli)MOD;
	}
	val = t1;
	return val;
}
int main(){
	int m, x, ans;
	lli t1, cnt;
	scanf("%d", &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &x);
		p[x]++;
	}
	for(int i = 2 ; i < N ; i++){
		if(p[i] > 0){
			v.PB(i);
			vcnt.PB(p[i]);
			vp.PB(1);
		}
	}
	for(int i = 0 ; i < v.size() ; i++){
		t1 = (lli)vcnt[i] * (lli)(vcnt[i]+1);
		t1 /= (lli)2;
		t1 %= (lli)(MOD-1);
		vp[i] = getp(v[i], t1);
	}
	cnt = 1;
	ans = 1;
	for(int i = 0 ; i < v.size() ; i++){
		t1 = (lli)getp(vp[i], cnt) * (lli)getp(ans, (lli)(vcnt[i]+1));
		t1 %= (lli)MOD;
		ans = t1;
		cnt *= (lli)(vcnt[i]+1);
		cnt %= (lli)(MOD-1);
	}
	printf("%d", ans);
	return 0;
}