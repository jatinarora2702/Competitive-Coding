#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

int main(){
	lli n, a, b, c, d, cnt;
	cin >> n >> a >> b >> c;
	d = b - c;
	cnt = 0;
	if(a <= d){
		cnt = n / a;
	}
	else{
		cnt = (n-b) / d;
		if(cnt < 0)
			cnt = 0;
		n -= d*cnt;
		cnt += n / b;
		n -= (n / b)*d;
		cnt += n / a;
	}
	cout << cnt << endl;
	return 0;
}