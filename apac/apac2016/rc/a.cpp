#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 105
// #define all(x) (x).begin(), (x).end()
using namespace std;

int s[N], w[N];
map < string, vector < int > > mp;
vector < pair < int, string > > v;

bool fn1(pair < int, string > p1, pair < int, string > p2) {
	if(p1.FF == p2.FF) {
		return p1.SS < p2.SS;
	}
	return p1.FF > p2.FF;
}

bool fn(int x, int y) {
	return x > y;
}

int main() {
	int t, p, n, m, h, temp, i, j;
	string name;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		printf("Case #%d:\n", h);
		mp.clear();
		scanf("%d", &p);
		for(i = 0 ; i < p ; i++) {
			scanf("%d", &s[i]);
		}
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &w[i]);
			for(j = 0 ; j < p ; j++) {
				cin >> name;
				mp[name].PB(s[j] * w[i]);
			}
		}
		scanf("%d", &m);
		v.clear();
		for(auto it : mp) {
			sort((it.SS).begin(), (it.SS).end(), fn);
			temp = 0;
			for(i = 0 ; i < m ; i++) {
				if(i == (it.SS).size())
					break;
				temp += (it.SS)[i];
			}
			v.PB(MP(temp, it.FF));
		}
		sort(v.begin(), v.end(), fn1);
		j = 0;
		for(i = 0 ; i < v.size() ; i++) {
			if(i == 0 || v[j].FF != v[i].FF)
				j = i;
			cout << (j+1) << ": " << v[i].SS << "\n";
		}
	}
	return 0;
}