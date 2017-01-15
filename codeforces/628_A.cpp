#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

#define PB push_back
#define MP make_pair
#define FF first
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = (int)(1e9+7);
const int MOD = (int)(1e9+7);

int a[100];
int main(){
	int n, b, p, ans1, ans2, m, k, np, x;
	scanf("%d%d%d", &n, &b, &p);
	ans2 = p * n;
	a[0] = 1;
	a[1] = 2;
	m = 4;
	k = 2;
	while(m <= 500){
		a[k++] = m;
		m *= 2;
	}
	m = 0;
	np = n;
	while(np > 1){
		//cout << "np:" << np << endl;
		x = upper_bound(a, a+k, np) - a;
		x--;
		//cout << "x:" << a[x] << endl;
		m += a[x]/2;
		np -= a[x]/2;
	}
	ans1 = m * (2*b+1);
	printf("%d %d\n",ans1, ans2); 
	return 0;
}
