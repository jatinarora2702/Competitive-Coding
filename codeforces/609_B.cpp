#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int a[15], b[15];
int main(){
	int n, m, x, cnt;
	lli t;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		a[x]++;
	}
	cnt = 0;
	for(int i = m ; i >= 1 ; i--){
		b[i] = cnt;
		cnt += a[i];
	}
	t = 0;
	for(int i = 1 ; i <= m ; i++){
		t += (lli)b[i] * (lli)a[i];
	}
	cout << t;
	return 0;
}