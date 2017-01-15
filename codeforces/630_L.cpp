#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second
#define MP make_pair
#define N 1000
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9+7;
const int MOD = 1e9+7;

int a[10], b[10], c[10];
int main(){
	int n, m, up, lst, k;
	lli ans, mans;
	scanf("%d", &n);
	k = 0;
	m = n;
	while(m != 0){
		a[k++] = m % 10;
		m /= 10;
	}
	b[4] = a[4];
	b[3] = a[2];
	b[2] = a[0];
	b[1] = a[1];
	b[0] = a[3];
	up = 10000 * b[4] + 1000 * b[3] + 100 * b[2];
	lst = 10 * b[1] + b[0];
	ans = 10LL * (lli)up * (lli)up * (lli)lst * (lli)lst * (lli)lst;
	ans += 5LL * (lli)up * (lli)lst * (lli)lst * (lli)lst * (lli)lst;
	ans += (lli)lst * (lli)lst * (lli)lst * (lli)lst * (lli)lst;
	mans = ans;
	k = 0;
	while(mans != 0 && k < 5){
		c[k++] = (int)(mans % 10LL);
		mans /= 10LL;
	}
	for(int i = 4 ; i >= 0 ; i--)
		cout << c[i];
	cout << endl;
}
