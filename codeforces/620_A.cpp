#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	lli cnt, cnt1, cnt2, x, y, x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x = x2 - x1;
	y = y2 - y1;
	cnt = min(abs(x), abs(y));
	if(x < 0)
		x += cnt;
	else
		x -= cnt;
	if(y < 0)
		y += cnt;
	else
		y -= cnt;
	cnt1 = abs(x);
	if(x < 0)
		x += cnt1;
	else
		x -= cnt1;
	cnt2 = abs(y);
	if(y < 0)
		y += cnt2;
	else
		y -= cnt2;
	cnt += (cnt1 + cnt2);
	cout << cnt;
	return 0;
}