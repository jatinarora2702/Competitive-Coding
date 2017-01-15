#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
int main(){
	int n, v, rem;
	lli s, cnt;
	scanf("%d", &n);
	s = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		s += (lli)a[i];
	}
	sort(a, a+n);
	v = s / (lli)n;
	rem = s % (lli)n;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == v)
			a[i] = -1;
		else if(a[i] == (v+1) && rem > 0){
			a[i] = -1;
			rem--;
		}
	}
	cnt = 0;
	for(int i = n-1 ; i >= 0 ; i--){
		if(a[i] < v)
			break;
		if(a[i] != -1){
			if(rem > 0){
				cnt += (lli)(abs((v+1) - a[i]));
				rem--;
			}
			else{
				cnt += (lli)(abs(v - a[i]));
			}
		}
	}
	cout << cnt;
	return 0;
}