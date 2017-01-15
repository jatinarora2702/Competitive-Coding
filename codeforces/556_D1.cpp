#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX (int)2e5+5
using namespace std;
typedef long long ll;
int ans[MAX];
pair < ll, ll > arr[MAX];
pair < ll ,int >  br[MAX];
pair < pair < ll, ll > , int > p[MAX];
bool cmp(pair < pair < ll, ll >, int > p1, pair < pair < ll, ll >, int > p2){
	if(p1.ff.ss != p2.ff.ss)
		return (p1.ff.ss < p2.ff.ss);
	if(p1.ff.ff != p2.ff.ff)
		return (p1.ff.ff < p2.ff.ff);
	return (p1.ss < p2.ss);
}
int main() {
	int n, m, k;
	ll tmp;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i].ff >> arr[i].ss;
	n--;
	for(int i = 0 ; i < n ; i++)
		p[i] = make_pair(make_pair(arr[i+1].ff - arr[i].ss, arr[i+1].ss - arr[i].ff), i);
	set < pair < ll, int > > s;
	set < pair < ll, int > > :: iterator it;
	sort(p, p+n, cmp);
	for(int i = 0 ; i < m ; i++){
		cin >> tmp;
		br[i] = make_pair(tmp, i);
	}
	sort(br, br+m);
	k = 0;
	for(int i = 0 ; i < n ; i++){
			while(k < m && br[k].ff <= p[i].ff.ss)
				s.insert(br[k++]);
		it = s.lower_bound(make_pair(p[i].ff.ff, -1));
		if(it == s.end()){
			printf("No");
			return 0;
		}
		ans[p[i].ss] = it->ss;
		s.erase(it);
	}
	printf("Yes\n");
	for(int i = 0 ; i < n ; i++)
		printf("%d ", ans[i]+1);
	return 0;
}