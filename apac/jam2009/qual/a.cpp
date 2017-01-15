#include <bits/stdc++.h>
#define N 5005
#define PB push_back
using namespace std;

// works with c++11 : g++ -std=c++11 a.cpp
vector < string > vs, v[30][20], vans, vtemp, vchar;
vector < string > :: iterator it;
int main() {
	int l, d, n, i, j, f;
	string s;
	scanf("%d%d%d", &l, &d, &n);
	for(i = 0 ; i < d ; i++) {
		cin >> s;
		vs.PB(s);
	}
	sort(vs.begin(), vs.end());
	for(i = 0 ; i < vs.size() ; i++) {
		j = 0;
		for(auto its : vs[i]) {
			v[its-'a'][j].PB(vs[i]);
			j++;
		}
	}
	for(i = 0 ; i < n ; i++) {
		cin >> s;
		vans = vs;
		j = 0;
		f = 0;
		for(auto its : s) {
			if(its == '(') {
				f = 1;
				vchar.clear();
				continue;
			}
			if(its == ')') {
				vtemp.clear();
				vtemp.resize(N);
				it = set_intersection(vans.begin(), vans.end(), vchar.begin(), vchar.end(), vtemp.begin());
				vtemp.resize(it - vtemp.begin());
				vans = vtemp;
				f = 0;
				j++;
				continue;
			}
			if(f == 1) {
				vtemp.clear();
				vtemp.resize(N);
				it = set_union(v[its-'a'][j].begin(), v[its-'a'][j].end(), vchar.begin(), vchar.end(), vtemp.begin());
				vtemp.resize(it - vtemp.begin());
				vchar = vtemp;
			}
			else if(f == 0) {
				vtemp.clear();
				vtemp.resize(N);
				it = set_intersection(vans.begin(), vans.end(), v[its-'a'][j].begin(), v[its-'a'][j].end(), vtemp.begin());
				vtemp.resize(it - vtemp.begin());
				vans = vtemp;
				j++;
			}
		}
		printf("Case #%d: %lu\n", i+1, vans.size());
	}
	return 0;
}