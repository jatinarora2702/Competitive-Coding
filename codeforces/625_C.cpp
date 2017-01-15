#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define N 505

using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

int a[N][N];
int main(){
	int n, k, cnt;
	lli sum;
	scanf("%d%d", &n, &k);
	k--;
	cnt = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < k ; j++){
			a[i][j] = cnt++;
		}
	}
	sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += (lli)cnt;
		for(int j = k ; j < n ; j++){
			a[i][j] = cnt++;
		}
	}
	cout << sum << endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0  ; j < n ; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}