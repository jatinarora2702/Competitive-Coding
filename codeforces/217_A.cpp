#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,u,v,f,cnt;
	scanf("%d",&n);
	vector < pair < vector < int > , vector < int > > > v1;
	cnt = 0;
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d%d", &u, &v);
		f = 0;
		for(int j = 0 ; j < v1.size() ; j++ ) {
			for(int k1 = 0 ; k1 < v1[j].first.size() ; k1++ ) {
				if(v1[j].first[k1] == u){
					v1[j].second.push_back(v);
					f = 1;
					break;
				}
			}
			if(f == 1) 
				break;
			for(int k1 = 0 ; k1 < v1[j].second.size() ; k1++ ) {
				if(v1[j].second[k1] == v){
					v1[j].first.push_back(u);
					f = 1;
					break;
				}
			}
			if(f == 1)
				break;
		}
		if(f == 0) {
			cnt++;
			vector < int > vx(1,u);
			vector < int > vy(1,v);
			v1.push_back(make_pair(vx,vy));
		}
	}
	int sz = v1.size();
	printf("%d",cnt-1);
	return 0;
}