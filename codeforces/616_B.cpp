#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long int lli;
const int INF = 1e9+7;
int a[105][105];
int v[105];
int main(){
	int n, m, maxm, minm;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0 ; i < n ; i++){
		minm = INF;
		for(int j = 0 ; j < m ; j++){
			minm = min(minm, a[i][j]);
		}
		v[i] = minm;
	}
	maxm = 0;
	for(int i = 0 ; i < n ; i++){
		maxm = max(maxm, v[i]);
	}
	printf("%d", maxm);
	return 0;
}