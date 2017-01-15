#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 30
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int ONF = 1e9+7;

int a[N];
map < int, int > mp;
bool fn(int x, int y){
	return (x > y);
}
int main(){
	int n, minm;
	lli cnt;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	sort(a, a+n, fn);
	mp.clear();
	cnt = 0LL;
	minm = ONF;
	for(int i = 0 ; i < n ; i++){
		minm = min(minm, a[i]);
		while(minm > 0 && mp.count(minm) != 0){
			minm--;
		}
		if(minm > 0){
			mp[minm] = 1;
			cnt += (lli)minm;	
		}
	}
	cout << cnt << endl;
	return 0;
}