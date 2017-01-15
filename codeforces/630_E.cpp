#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define N 1000
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;

int main(){
	int x1, x2, y1, y2;
	lli k1, k2, val1, ans;
	scanf("%d%d%d%d", &x1, &y1, &x3, &y3);
	x2 = x3;
	y2 = y1;
	x4 = x1;
	y4 = y3;
	k1 = abs(x2 - x1);
	k2 = abs(y2 - y1);
	f1 = f2 = f3 = f4 = 0;
	if((x1 % 2 == 0 && y1 % 2 == 0) || (x1 % 2 != 0 && y1 % 2 != 0)){
		f1 = 1;
	}
	if((x2 % 2 == 0 && y2 % 2 == 0) || (x2 % 2 != 0 && y2 % 2 != 0)){
		f2 = 1;
	}
	if((x3 % 2 == 0 && y3 % 2 == 0) || (x3 % 2 != 0 && y3 % 2 != 0)){
		f3 = 1;
	}
	if((x4 % 2 == 0 && y4 % 2 == 0) || (x4 % 2 != 0 && y4 % 2 != 0)){
		f4 = 1;
	}
	val1 = k2 / 2;
	if(f1 == 0 && f4 == 1)
		val1++;
	if(f1 == 1)
		val1++;
	
	
	if(y1 % 2 == 0){
		val1 = (k2 + 1) / 2;
	}
	else{
		val1 = k2 / 2;
		if(k2 % 2 != 0)
			val1++;
	}
	ans = (lli)(val1 + (val1-1)) * (lli)((k1+1) / 2);
	if(k1 % 2 == 0){
		ans += val1;
		// if(y1 % 2 != 0)
		// 	ans += (lli)(val1);
		// else
		// 	ans += (lli)(val1-1);
	}
	cout << ans << endl;
	return 0;
}