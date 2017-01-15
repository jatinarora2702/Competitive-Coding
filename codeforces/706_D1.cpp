#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair

using namespace std;
typedef long long int lli;
typedef long double ld;
typedef set < int > si;
map < int, map < int, si > > mp;
map < int, int > mpst;
map < int, map < int, si > > :: iterator it;
map < int, si > :: iterator itm;
set < int > :: iterator its;
map < int, int > :: iterator it1;
int main() {
	int q, x, maxm, i, j, k, kn, posk, poskn, kf, knf;
	char ch;
	scanf("%d", &q);
	kf = 0;
	for(i = 30 ; i >= 22 ; i--)
		kf += (1 << i);
	knf = 0;
	for(i = 21 ; i >= 13 ; i--)
		knf += (1 << i);
	mpst[0] = 1;
	mp[0][0].insert(0);
	for(j = 0 ; j < q ; j++) {
		scanf(" %c %d", &ch, &x);
		// for(it1 = mpst.begin() ; it1 != mpst.end() ; it1++) {
		// 	printf("(%d, %d)", it1->FF, it1->SS);
		// }
		if(ch == '+') {
			mpst[x]++;
			if(mpst[x] == 1) {
				k = x & kf;
				kn = x & knf;
				// printf("k=%d | kn=%d\n", k, kn);
				mp[k][kn].insert(x);
			}
		}
		else if(ch == '-' && (mpst.find(x) != mpst.end())) {
			mpst[x]--;
			if(mpst[0] == 0)
				mpst[0] = 1;
			if(mpst[x] == 0) {
				mpst.erase(x);
				k = x & kf;
				kn = x & knf;
				mp[k][kn].erase(x);
				if(mp[k][kn].size() == 0)
					mp[k].erase(kn);
				if(mp[k].size() == 0)
					mp.erase(k);
			}
		}
		else if(ch == '?') {
			k = x & kf;
			kn = x & knf;
			// printf("1k=%d | kn=%d\n", k, kn);
			maxm = -1;
			posk = -1;
			for(it = mp.begin() ; it != mp.end() ; it++) {
				if(maxm < (k^(it->FF))) {
					// printf("it: %d | k: %d | kxor: %d | maxm: %d | posk: %d\n", it->FF, k, (k^(it->FF)), maxm, posk);
					maxm = (k^(it->FF));
					posk = it->FF;
				}
			}
			maxm = -1;
			poskn = -1;
			for(itm = mp[posk].begin() ; itm != mp[posk].end() ; itm++) {
				if(maxm < (kn^(itm->FF))) {
					// printf("it: %d | kn: %d | knxor: %d | maxm: %d | poskn: %d\n", itm->FF, kn, (kn^(itm->FF)), maxm, poskn);
					maxm = (kn^(itm->FF));
					poskn = itm->FF;
				}
			}
			maxm = -1;
			for(its = mp[posk][poskn].begin() ; its != mp[posk][poskn].end() ; its++) {
				// printf("{%d} ", *its);
				maxm = max(maxm, x^(*its));
			}
			printf("%d\n", maxm);
		}
	}
	return 0;
}