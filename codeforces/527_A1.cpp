#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	lli a, b, rem, temp, cnt;
	cin >> a >> b;
	cnt = 0;
	while(a != 0 && b != 0){
		if(a < b){
			temp = a;
			a = b;
			b = temp;
		}
		temp = a / b;
		cnt += temp;
		a -= (b * temp);

	}
	cout << cnt << "\n";
	return 0;
}