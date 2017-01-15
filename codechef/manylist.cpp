#include <bits/stdc++.h>
#define N 200005
using namespace std;
set < int > s[N];
int main(){
	int n, m, l, r, x, q;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &q);
		if(q == 0){
			scanf("%d%d%d", &l, &r, &x);
			l--;
			r--;
			for(int j = l ; j <= r ; j++)
				s[j].insert(x);
		}
		else if(q == 1){
			scanf("%d", &x);
			x--;
			cout << s[x].size() << endl;
		}
	}
	return 0;
}