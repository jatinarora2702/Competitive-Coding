#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
using namespace std;

typedef long long int lli;
typedef long double ld;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005

int a[N], b[N];
vector < char > vec;

int main() {
	int m, i, n, minm, j, n1;
	string s;
	cin >> m >> s;
	n = 0;
	i = 0;
	while(n < s.size()) {
		n += m;
		if(n >= s.size()) {
			// a[i++] = s.size() - 1;
			break;
		}
		else {
			a[i++] = n-1;
		}
	}
	n1 = i;
	n = s.size();
	i = n1-1;
	while(n >= 0) {
		n -= m;
		if(n < 0) {
			// b[i--] = 0;
			break;
		}
		else {
			b[i--] = n;
		}
	}
	printf("n1=%d\n", n1);
	for(i = 0 ; i < n1 ; i++) {
		printf("(%d, %d) ", a[i], b[i]);
	}
	for(i = 0 ; i < n1 ; i++) {
		minm = -1;
		for(j = b[i] ; j <= a[i] ; j++) {
			if(minm == -1 || s[minm] > s[j]) {
				minm = j;
			}
		}
		if(minm > -1) {
			vec.PB(s[minm]);
		}
	}
	sort(vec.begin(), vec.end());
	for(i = 0 ; i < vec.size() ; i++) {
		printf("%c", vec[i]);
	}
	printf("\n");
	return 0;
}