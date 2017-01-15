#include <bits/stdc++.h>
#define N 10005
#define PB push_back
using namespace std;

int a[N];
vector < int > v;
set < int > st;
vector < int > vp[N];
void getprimes() {
	int i, j;
	v.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			v.PB(i);
			if(i * i < N) {
				for(j = i*i ; j < N ; j+=i) {
					a[j] = 1;
				}
			}
		}
	}
}

void getmults() {
	int i, j, k;
	for(i = 0 ; i < v.size() ; i++) {
		for(j = 0 ; j < v.size() ; j++) {
			k = pow(v[i], v[j]-1);
			if(k < N) {
				vp[v[i]].PB(k);
			}
			else {
				break;
			}
		}
	}
	// for(i = 0 ; i < N ; i++) {
	// 	if(vp[i].size() > 0) {
	// 		printf("%d: ", i);
	// 		for(j = 0 ; j < vp[i].size() ; j++) {
	// 			printf("%d ", vp[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// }
}

int main() {
	int t, k1, k2, l, r, i, j;
	scanf("%d", &t);
	getprimes();
	getmults();
	while(t--) {
		scanf("%d%d", &l, &r);
		st.clear();
		for(i = 0 ; i < v.size() ; i++) {
			k1 = lower_bound(vp[v[i]].begin(), vp[v[i]].end(), l) - vp[v[i]].begin();
			k2 = upper_bound(vp[v[i]].begin(), vp[v[i]].end(), r) - vp[v[i]].begin();
			if(k2-k1 > 0){
				// printf("ans:%d\n", k2-k1);
				for(j = k1 ; j < k2 ; j++) {
					st.insert(vp[v[i]][j]);
				}
			}
		}
		if(st.size() == 0) {
			printf("-1\n");
		}
		else {
			for(auto it : st) {
				printf("%d ", it);
			}
			printf("\n");
		}
	}
	return 0;
}