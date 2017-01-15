#include <bits/stdc++.h>
#define N 25
using namespace std;
typedef long long int lli;
int invalid[N];
lli a[N];
int poss(lli s, int n){
	if(s == 0)
		return 1;
	if(s < 0)
		return 0;
	if(n == 1){
		if(!invalid[0] && a[0] == s){
			invalid[0] = 1;
			return 1;
		}
		return 0;
	}
	if(!invalid[n-1]){
		int temp;
		invalid[n-1] = 1;
		temp = poss(s - (lli)a[n-1], n-1);
		if(temp == 1)
			return 1;
		invalid[n-1] = 0;
		return poss(s, n-1);
	}
	return poss(s, n-1);
}
int main() {
	int t, n, k, f, stat;
	lli s, s1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		s = 0;
		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &a[i]);
			s += a[i];
		}
		if(k <= n && s % (lli)k == 0){
			// cout << "s:" << s << endl;
			s1 = s / (lli)k;
			// cout << "s1:" << s1 << endl;
			f = 1;
			for(int i = 0 ; i < n ; i++)
				invalid[i] = 0;
			for(int i = 0 ; i < k ; i++){
				// cout << i << ":";
				// for(int j = 0 ; j < n ; j++)
				// 	cout << invalid[j] << " ";
				// cout << endl;
				stat = poss(s1, n);
				if(stat == 0){
					f = 0;
					break;
				}
			}
			if(f == 0)
				printf("no\n");
			else
				printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}