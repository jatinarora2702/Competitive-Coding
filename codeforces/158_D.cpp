#include <bits/stdc++.h>
#define PB push_back

using namespace std;

const int INF = 1e9 + 7;
const int N = 20005;

typedef vector < int > vi;
typedef set < int > sti;

vi vp, vf, vtemp1, vtemp2;
sti sf;
sti :: iterator it;
int a[N], n;

void findprimes() {
	int i, j;
	vp.PB(2);
	for(i = 3 ; i <= n / 2 ; i += 2) {
		if (a[i] == 0) {
			vp.PB(i);
			for(j = i*2 ; j < n ; j += i)
				a[j] = 1;
		}
	}
}

void findfactors() {
	int i, j, p;
	findprimes();
	for(i = 0 ; i < vp.size() ; i++) {
		p = vp[i];
		vtemp1.clear();
		vtemp2.clear();
		while(n % p == 0) {
			vtemp1.PB(p);
			p *= vp[i];
		}
		for(j = 0 ; j < vtemp1.size() ; j++) {
			for(it = sf.begin() ; it != sf.end() ; it++) {
				p = (*it) * vtemp1[j];
				if (n % p == 0)
					vtemp2.PB(p);
			}
		}
		for(j = 0 ; j < vtemp1.size() ; j++)
			sf.insert(vtemp1[j]);
		for(j = 0 ; j < vtemp2.size() ; j++)
			sf.insert(vtemp2[j]);
	}
	sf.insert(1);
	for(it = sf.begin() ; it != sf.end() ; it++)
		vf.PB(*it);
}

int getsum(int p) {
	int i, smax;
	if (p * 3 > n)
		return -INF;
	vtemp1.clear();
	for(i = 0 ; i < p ; i++)
		vtemp1.PB(0);
	for(i = 0 ; i < n ; i++)
		vtemp1[i % p] += a[i];
	smax = -INF;
	for(i = 0 ; i < p ; i++)
		smax = max(smax, vtemp1[i]);
	return smax;
}

int main() {
	int maxm, i;
	scanf("%d", &n);
	findfactors();
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	maxm = -INF;
	for(i = 0 ; i < vf.size() ; i++)
		maxm = max(maxm, getsum(vf[i]));
	printf("%d\n", maxm);
	return 0;
}