#include <bits/stdc++.h>
#define FF first
#define SS second
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
map < int , int > mp;
map < int, int > :: iterator it, it1;
int main() {
	int n, t, m, x;
	lli cnt;
	scanf("%d", &t);
	while(t--){
		mp.clear();
		scanf("%d%d%d", &n, &m, &x);
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
			mp[a[i]]++;
		}
		cnt = 0;
		for(it = mp.begin() ; it != mp.end() ; it++){
			for(it1 = it ; it1 != mp.end() ; it1++){
				if((it->FF + it1->FF) % m <= x){
					// cout << "a:" << it->FF << " b:" << it1->FF << endl;
					cnt += (lli)(it->SS) * (lli)(it1->SS);
					if(it->FF != it1->FF)
						cnt += (lli)(it->SS) * (lli)(it1->SS);
				}
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}