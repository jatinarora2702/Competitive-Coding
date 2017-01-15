#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
	int a, b, t, rem, n, ans, cnt;
	scanf("%d%d", &a, &b);
	cnt = 0;
	for(int i = a ; i <= b ; i++){
		n = i;
		t = 0;
		while(n != 0){
			rem = n % 10;
			n /= 10;
			switch(rem){
				case 0: ans = 6; break;
				case 1: ans = 2; break;
				case 2: ans = 5; break;
				case 3: ans = 5; break;
				case 4: ans = 4; break;
				case 5: ans = 5; break;
				case 6: ans = 6; break;
				case 7: ans = 3; break;
				case 8: ans = 7; break;
				case 9: ans = 6; break;
			}
			t += ans;
		}
		cnt += t;
	}
	printf("%d\n", cnt);
	return 0;
}