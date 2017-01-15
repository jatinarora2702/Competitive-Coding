#include <bits/stdc++.h>
#define N 100005
#define M 1000005
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long int lli;
int a[N], b[N], stat[M], v1[N];
vector < int > v[M];
// pair < int, int > p[N];
// bool fn(pair < int, int > p1, pair < int, int > p2){
// 	if(p1.SS <= p2.SS)
// 		return true;
// 	return false;
// }
int main() {
	int n, r, avg, j, k, rem, l, j1;
	lli his, tot, dif, cnt;
	scanf("%d%d%d", &n, &r, &avg);
	his = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &a[i], &b[i]);
		// p[i] = make_pair(a[i], b[i]);
		his += (lli)a[i];
		v[b[i]].PB(a[i]);
		stat[b[i]] = 1;
	}
	l = 0;
	for(int i = 0 ; i < M ; i++){
		if(stat[i] == 1){
			// cout << "p:" << i << endl;
			v1[l++] = i;
		}
	}
	tot = (lli)avg * (lli)n;
	dif = tot - his;
	j = 0;
	cnt = 0;
	// cout << "l=" << l << endl;
	j1 = 0;
	while(j1 < l){
		j = 0;
		// cout << v1[j1] << endl;
		while(j < v[v1[j1]].size() && dif > 0){
			// cout << v1[j1] << endl;
			rem = r - v[v1[j1]][j];
			k = (int)min((lli)rem, dif);
			cnt += (lli)v1[j1] * (lli)k;
			dif -= (lli)k;
			j++;
		}
		j1++;
	}
	cout << cnt << endl;
	return 0;
}