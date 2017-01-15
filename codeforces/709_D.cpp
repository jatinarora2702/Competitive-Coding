#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005

using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

map < int, int > mpf;
vector < int > v;
set < int > sttemp, stfull;
int a[N];
int main() {
	int a00, a01, a10, a11, i, n1, n0, x0, x1, y1, y0, f, j, m;
	lli temp;
	mpf[1] = 1;
	temp = 1LL;
	for(i = 2 ; i < 100 ; i++) {
		temp = temp * (lli)i;
		if(temp > (lli)INF)
			break;
		mpf[i] = (int)temp;
	}
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	n0 = mpf[a00];
	n0++;
	if(a00 == 0) {
		if(a01 == 0 && a10 == 0)
			n0 = 0;
		else
			n0 = 1;
	}
	n1 = mpf[a11];
	n1++;
	if(a11 == 0) {
		if(a01 == 0 && a10 == 0)
			n1 = 0;
		else
			n1 = 1;
	}
	
	v.PB(2);
	for(i = 3 ; i < N ; i+=2) {
		if(a[i] == 0) {
			v.PB(i);
			if(i < sqrt(N)) {
				for(j = i*i ; j < N ; j+=i)
					a[j] = 1;
			}
		}
	}
	m = a01;
	stfull.insert(1);
	for(i = 0 ; i < v.size() ; i++) {
		temp = (int)v[i];
		sttemp.clear();
		while(m % temp == 0) {
			for(auto it : stfull) {
				sttemp.insert(it * (int)temp);	
			}
			temp *= (lli)v[i];
		}
		temp /= (lli)v[i];
		m /= (int)temp;
		stfull = sttemp;
	}
	stfull.insert(m);
	stfull.insert(a01);
	// for(auto it : stfull) {
	// 	printf("(%d)\n", it);
	// }
	f = 0;
	for(auto it : stfull) {
		x0 = it;
		x1 = a01 / it;
		y0 = n0 - x0;
		y1 = n1 - x1;
		// printf("%d %d %d %d\n", x0, x1, y0, y1);
		if(y0 < 0 || y1 < 0)
			continue;
		temp = (lli)y1 * (lli)n0 + (lli)x1 * (lli)y0;
		if(temp != (lli)a10)
			continue;
		f = 1;
		break;
	}
	if(f == 1) {
		for(i = 0 ; i < y1 ; i++) {
			printf("%d", 1);
		}
		for(i = 0 ; i < x0 ; i++) {
			printf("%d", 0);
		}
		for(i = 0 ; i < x1 ; i++) {
			printf("%d", 1);
		}
		for(i = 0 ; i < y0 ; i++) {
			printf("%d", 0);
		}
		printf("\n");
	}
	else {
		m = a10;
		stfull.clear();
		stfull.insert(1);
		for(i = 0 ; i < v.size() ; i++) {
			temp = (int)v[i];
			sttemp.clear();
			while(m % temp == 0) {
				for(auto it : stfull) {
					sttemp.insert(it * (int)temp);	
				}
				temp *= (lli)v[i];
			}
			temp /= (lli)v[i];
			m /= (int)temp;
			stfull = sttemp;
		}
		stfull.insert(m);
		stfull.insert(a10);
		// for(auto it : stfull) {
		// 	printf("!(%d)\n", it);
		// }
		f = 0;
		for(auto it : stfull) {
			x0 = it;
			x1 = a10 / it;
			y0 = n0 - x0;
			y1 = n1 - x1;
			// printf("%d %d %d %d\n", x0, x1, y0, y1);
			if(y0 < 0 || y1 < 0)
				continue;
			temp = (lli)y0 * (lli)n1 + (lli)x0 * (lli)y1;
			if(temp != (lli)a01)
				continue;
			f = 1;
			break;
		}
		if(f == 1) {
			for(i = 0 ; i < y0 ; i++) {
				printf("%d", 0);
			}
			for(i = 0 ; i < x1 ; i++) {
				printf("%d", 1);
			}
			for(i = 0 ; i < x0 ; i++) {
				printf("%d", 0);
			}
			for(i = 0 ; i < y1 ; i++) {
				printf("%d", 1);
			}
			printf("\n");
		}
		else {
			printf("Impossible\n");
		}
	}
	return 0;
}