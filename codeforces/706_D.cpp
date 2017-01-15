#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair

using namespace std;
map < int, set < int > > mp;
map < int, int > mpst;
map < int, set < int > > :: iterator it;
set < int > :: iterator its;
// map < int, int > :: iterator it1;
int main() {
	int q, x, maxm, i, j, k, posk, kf;
	char ch;
	scanf("%d", &q);
	kf = 0;
	for(i = 30 ; i >= 22 ; i--)
		kf += (1 << i);
	mpst[0] = 1;
	mp[0].insert(0);
	for(j = 0 ; j < q ; j++) {
		scanf(" %c %d", &ch, &x);
		// for(it1 = mpst.begin() ; it1 != mpst.end() ; it1++) {
		// 	printf("(%d, %d)", it1->FF, it1->SS);
		// }
		if(ch == '+') {
			mpst[x]++;
			if(mpst[x] == 1) {
				k = x & kf;
				// printf("k=%d\n", k);
				mp[k].insert(x);
			}
		}
		else if(ch == '-' && (mpst.find(x) != mpst.end())) {
			mpst[x]--;
			if(mpst[0] == 0)
				mpst[0] = 1;
			if(mpst[x] == 0) {
				mpst.erase(x);
				k = x & kf;
				mp[k].erase(x);
				if(mp[k].size() == 0)
					mp.erase(k);
			}
		}
		else if(ch == '?') {
			k = x & kf;
			// printf("1k=%d\n", k);
			maxm = -1;
			posk = -1;
			for(it = mp.begin() ; it != mp.end() ; it++) {
				if(maxm < (k^(it->FF))) {
					// printf("it: %d | k: %d | xor: %d | maxm: %d | pos: %d\n", it->FF, k, k^it->FF, maxm, posk);
					maxm = k^it->FF;
					posk = it->FF;
				}
			}
			maxm = -1;
			for(its = mp[posk].begin() ; its != mp[posk].end() ; its++) {
				// printf("{%d} ", *its);
				maxm = max(maxm, x^*its);
			}
			printf("%d\n", maxm);
		}
	}
	return 0;
}