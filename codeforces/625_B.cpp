#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 100005
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

char a[N], b[N];
int c[N], m, n;
int check(int pos){
	for(int i = 0 ; i < n; i++){
		if(pos + i >= m)
			return 0;
		if(a[pos+i] != b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int j, en, cnt;
	scanf("%s%s", a, b);
	m = strlen(a);
	n = strlen(b);
	for(int i = 0 ; i < m ; i++){
		if(a[i] == b[0]){
			c[i] = check(i);
		}
		else
			c[i] = 0;
	}
	// for(int i = 0 ; i < m ; i++)
	// 	printf("%d ", c[i]);
	// printf("\n");
	cnt = 0;
	en = 1;
	for(int i = 0 ; i < m ; i++){
		if(i == j && en == 0)
			en = 1;
		if(c[i] == 1 && en == 1){
			cnt++;
			j = i+n;
			en = 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}