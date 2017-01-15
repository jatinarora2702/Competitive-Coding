#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long int lli;
typedef pair < int, int > pii;
const int MOD = 1e9+7;
const lli MAX = 1e18+7;
int main(){
	lli l, r, p, prev;
	int k, f;
	cin >> l >> r >> k;
	p = 1;
	prev = 1;
	f = 0;
	while(p < l){
		p *= (lli)k;
		if(prev != p / k){
			printf("-1");
			return 0;
		}
		prev = p;
	}
	while(p <= r){
		cout << p << " ";
		p *= (lli)k;
		f = 1;
		if(prev != p / k){
			break;
		}
		prev = p;
	}
	if(f == 0)
		printf("-1");
	return 0;
}