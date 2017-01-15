#include <bits/stdc++.h>
#define N 5005
using namespace std;
typedef long long int lli;
char a[N];
int dp[N][N], n;
const int MOD = 1e9+7;
inline int getans(int ndig, int in){
	if(in >= n || ndig >= n){
		return 0;
	}
	// cout << "ndig=" << ndig << " in=" << in << endl;
	if(dp[ndig][in] == -1){
		int l, f, ans, k;
		lli t;
		l = n - in;
		ans = 0;
		if(a[in] != '0' && l >= ndig){
			if(l > ndig)
				ans++;
			f = 0;
			for(int i = 0 ; i < ndig ; i++){
				if((a[in+i]-'0') > (a[in-ndig+i]-'0')){
					f = 1;
					break;
				}
				else if((a[in+i]-'0') < (a[in-ndig+i]-'0')){
					break;
				}
			}
			if(l == ndig && f == 1)
				ans++;
			if(f == 1 && in+2*ndig <= n && a[in+ndig] != '0'){
				t = (lli)ans + (lli)getans(ndig, in+ndig);
				t %= (lli)MOD;
				ans = t;
			}
			// cout << "ndig=" << ndig << " in=" << in << " ans=" << ans << endl;
			for(int i = ndig+1 ; i <= (l/2) ; i++){
				if(a[in+i] == '0')
					continue;
				t = (lli)ans + (lli)getans(i, in+i);
				t %= (lli)MOD;
				ans = t;
			}
		}
		dp[ndig][in] = ans;
		// cout << "cndig=" << ndig << " cin=" << in << " ans=" << ans << endl;
	}
	return dp[ndig][in];
}
int main(){
	scanf("%d%s", &n, a);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			dp[i][j] = -1;
	}
	printf("%d", getans(0, 0));
	return 0;
}