#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define N 100005
using namespace std;
const int INF = 1e9+7;
vector < int > v[205];
int a[205][100005];
map < int, int > mp, cnt;
map < int, int > :: iterator it;
pair < int, int > p[N];
int main(){
	int n, s, lar, minm, rem, temp, i1, val;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &p[i].FF);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &p[i].SS);
	for(int i = 0 ; i < n ; i++){
		v[p[i].SS].PB(p[i].FF);
		mp[p[i].FF] += p[i].SS;
		cnt[p[i].FF]++;
	}
	for(int i = 1 ; i <= 200 ; i++)
		sort(v[i].begin(), v[i].end());
	// cout << "v:\n";
	// for(int i = 1 ; i <= 200 ; i++){
	// 	if(v[i].size() > 0){
	// 		cout << i << ":";
	// 		for(int j = 0 ; j < v[i].size() ; j++)
	// 			cout << v[i][j] << " ";
	// 		cout << endl;
	// 	}
	// }
	// cout << "mp:";
	// for(it = mp.begin() ; it != mp.end() ; it++){
	// 	cout << "[" << it->FF << ", " << it->SS << "] ";
	// }
	// cout << endl;
	// cout << "cnt:";
	// for(it = cnt.begin() ; it != cnt.end() ; it++){
	// 	cout << "[" << it->FF << ", " << it->SS << "] ";
	// }
	// cout << endl;
	for(int i = 1 ; i <= 200 ; i++){
		// cout << "in" << endl;
		if(v[i].size() > 0){
			for(int j = 0 ; j < v[i][0] ; j++)
				a[i][j] = 0;
			for(int j = 0 ; j < v[i].size()-1 ; j++){
				for(int k = v[i][j] ; k < v[i][j+1] ; k++)
					a[i][k] = j+1;
			}
			i1 = v[i].size();
			for(int j = v[i][i1-1] ; j < N ; j++)
				a[i][j] = v[i].size();	
		}
	}
	// cout << "a window:\n";
	// for(int i = 0 ; i < 10 ; i++){
	// 	for(int j = 0 ; j < 10 ; j++)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << "a:" << endl;
	// for(int i = 1 ; i <= 200 ; i++){
	// 	for(int j = 0 ; j < N-1 ; j++){
	// 		if(a[i][j])
	// 	}
	// }
	s = 0;
	for(it = mp.begin() ; it != mp.end() ; it++)
		s += it->SS;
	lar = n;
	minm = INF;
	for(it = mp.begin() ; it != mp.end() ; it++){
		s -= it->SS;
		lar -= cnt[it->FF];
		val = s;
		// cout << "x:" << cnt[it->FF];
		rem = n - 2*cnt[it->FF] - lar + 1;
		// cout << "rem:" << rem << endl;
		if(rem < 0)
			rem = 0;
		i1 = 1;
		while(i1 <= 200 && rem > 0){
			temp = min(rem, a[i1][it->FF-1]);
			val += temp * i1;
			rem -= temp;
			i1++;
		}
		minm = min(minm, val);
	}
	printf("%d", minm);
	return 0;
}