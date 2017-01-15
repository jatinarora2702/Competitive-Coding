#include <bits/stdc++.h>
#define ff first
#define ss second
#define K 35
#define N 2005
using namespace std;
bool cmp(pair < int, int > p1, pair < int, int > p2){
	return (p1.ss-p1.ff) < (p2.ss-p2.ff);
}
int main(){
	int t, n, k, x, y;
	pair < int, int > p[K];
	char s[N];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0 ; i < k ; i++){
			scanf("%d%d", &x, &y);
			p[i] = make_pair(x, y);
		}
		for(int i = 0 ; i < n ; i++)
			s[i] = '.';
		sort(p, p+n, cmp);
		for(int i = 0 ; i < k ; i++){
			s[p[i].ss] = ')';
			s[p[i].ff] = '(';
		}
		for(int i = 0 ; i < n ; i++){
			
		}
	}
}