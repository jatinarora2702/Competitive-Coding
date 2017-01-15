#include <bits/stdc++.h>
#define ff first
#define ss second
#define N 4000
#define INF 1000000007
using namespace std;
int main(){
	// cout << "yy\n";
	int n, m, a[N], minsum, sum, x, y;
	set < int > knows[N];
	// cout << "qq\n";
	pair < int, int > p[N];
	// cout << "pp" << endl;
	for(int i = 0 ; i < N ; i++)
		a[i] = 0;
	// cout << "rr\n";
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		p[i] = make_pair(x, y);
		a[x]++;
		a[y]++;
		knows[x].insert(y);
		knows[y].insert(x);
	}
	minsum = INF;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if((knows[i].find(p[j].ff) != knows[i].end()) && (knows[i].find(p[j].ss) != knows[i].end())) {
				sum = a[i] + a[p[j].ff] + a[p[j].ss] - 6;
				if(sum < minsum)
					minsum = sum;
			}	
		}
	}
	if(minsum == INF)
		printf("-1");
	else
		printf("%d", minsum);
	return 0;
}