#include <bits/stdc++.h>
#define N 105
using namespace std;
int a[N];
typedef long long int lli;
int main(){
	int n, cnt;
	lli ans;
	scanf("%d", &n);
	for(int i = 0 ; i < n;  i++){
		scanf("%d", &a[i]);
	}
	cnt = 0;
	ans = (lli)1;
	int f = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == 1){
			if(f == 1)
				ans *= (lli)(cnt+1);
			cnt = 0;
			f = 1;
		}
		else
			cnt++;
	}
	if(f == 0)
		ans = 0;
	cout << ans << endl;
	return 0;
}