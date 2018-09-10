#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

lli arr[20];

int getlen(lli n) {
	int d;
	d = 0;
	while(n > 0LL) {
		d++;
		n /= 10LL;
	}
	return d;
}

lli getans(lli n, int f) {
	lli ans, temp, mt, temp1;
	int k1, k2, k;
	ans = 1LL;
	k1 = n % 10LL;
	n /= 10LL;
	if(n == 0LL) {
		ans = (f == 0) ? k1 : (10-k1);
		ans--;
		return ans;
	}
	temp = 0LL;
	temp1 = 1LL;
	mt = 0LL;
	while(n >= 10LL) {
		ans *= 10LL;
		k = n % 10LL;
		n /= 10LL;
		temp += temp1*k;
		temp1 *= 10LL;
		mt = mt*10LL + 9LL; 
	}
	temp = (f == 0) ? temp : (mt-temp);
	k2 = n % 10LL;
	ans *= (f == 0) ? (k2-1) : (9-k2);
	ans += temp;
	if(f == 1 && k2 >= k1)
		ans ++;
	if(f == 0 && k2 <= k1)
		ans ++;
	if(k1 == k2)
		ans--;
	return ans;
}

int main() {
	int i, la, lb;
	lli a, b, ans, s;
	arr[0] = 0LL;
	arr[1] = 9LL;
	arr[2] = 9LL;
	for(i = 3 ; i < 20 ; i++)
		arr[i] = arr[i-1] * 10LL;
	cin >> a >> b;
	la = getlen(a);
	lb = getlen(b);
	ans = 0LL;
	for(i = la ; i <= lb ; i++)
		ans += arr[i];
	ans -= getans(a, 0);
	ans -= getans(b, 1);
	cout << ans << endl;
	return 0;
}