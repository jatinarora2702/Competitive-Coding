#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 105
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

char a[N][N];
int main(){
	int n, cnt;
	lli ans;
	cnt = 0;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%s", a[i]);
	}
	ans= 0 ;
	for(int i = 0 ; i < n ; i++){
		cnt = 0;
		for(int j= 0 ;  j < n ; j++){
			if(a[i][j] == 'C')
				cnt++;
		}
		ans += ((lli)cnt * (lli)(cnt-1)) / (lli)2;
	}
	for(int j = 0 ; j < n ; j++){
		cnt = 0;
		for(int i = 0 ; i < n ; i++){
			if(a[i][j] == 'C')
				cnt++;
		}
		ans += ((lli)cnt * (lli)(cnt-1)) / (lli)2;
	}
	cout << ans << endl;
	return 0;
}