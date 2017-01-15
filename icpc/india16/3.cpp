#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 500005

int a[N], b[N], prefix[N], n, m, m1, m2;
vector < int > v, v1(2*N), v2(N);

void getprefix() {
	int i, j, k;
	prefix[0] = -1;
	for(i = 1 ; i < m-1 ; i++) {
		prefix[i] = -1;
		j = i-1;
		while(j >= 0) {
			k = prefix[j] + 1;
			if(v2[i] == v2[k]) {
				prefix[i] = k;
				break;
			}
			j = k-1;
		}
	}
}

int nummatchs() {
	int i, j, ans;
	getprefix();
	j = 0;
	ans = 0;
	for(i = 0 ; i < m2 ; i++) {
		if(v1[i] == v2[j]) {
			j++;
			if(j == m-1) {
				// printf("[%d]\n", i-m+2);
				ans++;
				j = prefix[j-1];
				j++;
			}
		}
		else {
			while(j > 0) {
				j = prefix[j-1];
				j++;
				if(v1[i] == v2[j]) {
					j++;
					break;
				}
			}
		}
	}
	return ans;
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0 ; i < m ; i++) {
		scanf("%d", &b[i]);
	}
	for(i = 0 ; i < n ; i++) {
		if(a[i] == 1) {
			v.PB(i);
		}
	}
	m1 = v.size();
	if(m == 1) {
		printf("%d\n", m1);
		return 0;
	}
	if(m1 < m) {
		printf("0\n");
		return 0;
	}
	for(i = 0 ; i < m1-1 ; i++) {
		v1[i] = v[i+1] - v[i];
	}
	v1[i] = n - v[i] + v[0];
	j = m1;
	for(i = 0 ; i < m-2 ; i++) {
		v1[j++] = v1[i];
	}
	for(i = 0 ; i < m-1 ; i++) {
		v2[i] = b[i+1] - b[i];
	}
	m2 = m1 + m - 2;
	printf("-------------------\n");
	for(i = 0 ; i < m2 ; i++) {
		printf("%d ", v1[i]);
	}
	printf("\n");
	for(i = 0 ; i < m-1 ; i++) {
		printf("%d ", v2[i]);
	}
	printf("\n");
	printf("-------------------\n");
	printf("%d\n", nummatchs());
	return 0;
}