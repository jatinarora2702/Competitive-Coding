#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;

#define N 1005

int p[30], a[N], dp1[N], dp2[N];
lli dp3[N];
int main() {
	int n, i, j, minm, ans1, ans2, ans3;
	string s;
	cin >> n >> s;
	for(i = 0 ; i < 26 ; i++)
		cin >> p[i];
	for(i = 0 ; i < s.length() ; i++) {
		a[i] = p[s[i]-'a'];
	}
	// printf("a: ");
	// for(i = 0 ; i < s.length() ; i++) {
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	for(i = 0 ; i < s.length() ; i++) {
		dp1[i] = 1;
		minm = a[i];
		for(j = i+1 ; j < s.length() ; j++) {
			if(j-i+1 > minm)
				break;
			if(j-i+1 > a[j])
				break;
			minm = min(minm, a[j]);
		}
		dp1[i] = j-i;
	}
	// printf("dp1: ");
	// for(i = 0 ; i < s.length() ; i++)
	// 	printf("%d ", dp1[i]);
	// printf("\n");
	ans2 = 0;
	for(i = 0 ; i < n ; i++)
		ans2 = max(ans2, dp1[i]);
	dp2[n-1] = 1;
	for(i = n-2 ; i >= 0 ; i--) {
		dp2[i] = INF;
		for(j = 0 ; j < dp1[i] ; j++) {
			dp2[i] = min(dp2[i], dp2[i+j+1]);
		}
		dp2[i]++;
	}
	// printf("dp2: ");
	// for(i = 0 ; i < s.length() ; i++)
	// 	printf("%d ", dp2[i]);
	// printf("\n");
	ans3 = dp2[0];
	dp3[n-1] = 1LL;
	for(i = n-2 ; i >= 0 ; i--) {
		dp3[i] = 0LL;
		for(j = 0 ; j < dp1[i] ; j++) {
			dp3[i] += dp3[i+j+1];
			dp3[i] %= (lli)INF;
			if(i+j+2 == s.length())
				break;
		}
		if(i+dp1[i] >= s.length()) {
			dp3[i]++;
			dp3[i] %= INF;
		}
	}
	// cout << "dp3: ";
	// for(i = 0 ; i < s.length() ; i++)
	// 	cout << dp3[i] << " ";
	// cout << endl;

	ans1 = (int)dp3[0];
	cout << ans1 << endl << ans2 << endl << ans3 << endl;
	return 0;
}