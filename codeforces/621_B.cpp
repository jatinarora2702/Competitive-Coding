#include <bits/stdc++.h>
#define N 200005
#define FF first
#define SS second
using namespace std;
typedef long long int lli;
map < int, int > mpsum, mpdif;
map < int, int > :: iterator it;
int main(){
	int n, x, y;
	lli ans;
	ans = 0;
	scanf("%d", &n);
	for(int i = 0 ; i <  n ; i++){
		scanf("%d%d", &x, &y);
		mpsum[x+y]++;
		mpdif[x-y]++;
	}
	for(it = mpsum.begin() ; it != mpsum.end() ; it++){
		ans += ((lli)it->SS * (lli)(it->SS - 1)) / (lli)2;
	}
	for(it = mpdif.begin() ; it != mpdif.end() ; it++){
		ans += ((lli)it->SS * (lli)(it->SS - 1)) / (lli)2;	
	}
	cout << ans << endl;
	return 0;
}