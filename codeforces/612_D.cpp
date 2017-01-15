#include <bits/stdc++.h>
#define N 10000005
#define PB push_back
#define FF first
#define SS second
using namespace std;
map < int, pair < int, int > > mp;
map < int, pair < int, int > > :: iterator it;
vector < pair < int, int > > v;
int a[N], b[N], c[N];
int main(){
	int n, k, x, y, cnt, f, cnt1, j;
	pair < int, int > p;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		mp[x].FF++;
		mp[y].SS--;
	}
	j = 0;
	for(it = mp.begin() ; it != mp.end() ; it++){
		a[j] = it->FF;
		b[j] = it->SS.FF;
		c[j] = it->SS.SS;
		j++;
	}
	// for(int i = 0 ; i < j ; i++){
	// 	cout << "a:" << a[i] << " b:" << b[i] << " c:" << c[i] << endl;
	// }
	cnt = 0;
	cnt1 = 0;
	f = 0;
	for(int i = 0 ; i < j ; i++){
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