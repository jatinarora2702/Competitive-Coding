#include <bits/stdc++.h>
#define N 10000005
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
using namespace std;
vector < pair < int, int > > v, mp;
int a[N], b[N], c[N];
int main(){
	int n, k, x, y, cnt, f, cnt1, j;
	pair < int, int > p;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		mp.PB(MP(x, 1));
		mp.PB(MP(y, -1));
	}
	sort(mp.begin(), mp.end());
	// for(int i = 0 ; i < mp.size() ; i++){
	// 	printf("(%d %d), ", mp[i].FF, mp[i].SS);
	// }
	// printf("\n");
	j = 0;
	a[0] = mp[0].FF;
	if(mp[0].SS == 1)
		b[0]++;
	else
		c[0]--;
	for(int i = 1 ; i < mp.size() ; i++){
		// cout << "q:" << mp[i].FF << endl;
		if(mp[i].FF == a[j]){
			// cout << "uu\n";
			if(mp[i].SS == 1)
				b[j]++;
			else
				c[j]--;	
		}
		else{
			// cout << "in\n";
			j++;
			a[j] = mp[i].FF;
			// cout << "j=" << j << endl;
			if(mp[i].SS == 1)
				b[j]++;
			else
				c[j]--;	
		}
	}
	// for(int i = 0 ; i <= j ; i++){
	// 	cout << "a:" << a[i] << " b:" << b[i] << " c:" << c[i] << endl;
	// }
	cnt = 0;
	cnt1 = 0;
	f = 0;
	for(int i = 0 ; i <= j ; i++){
		cnt += b[i];
		// cout << "a:" << a[i] << " cnt:" << cnt << endl;
		if(cnt >= k){
			if(f == 0){
				cnt1++;
				p.FF = a[i];
				f = 1;
			}
		}
		cnt += c[i];
		if(cnt < k){
			if(f == 1){
				p.SS = a[i];
				v.PB(p);
				f = 0;
			}	
		}
	}
	printf("%d\n", cnt1);
	for(int i = 0  ; i < v.size() ; i++)
		printf("%d %d\n", v[i].FF, v[i].SS);
	return 0;
}