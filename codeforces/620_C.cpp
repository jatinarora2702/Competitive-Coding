#include <bits/stdc++.h>
#define N 300005
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
using namespace std;
typedef pair < int, int > pii;
int a[N];
vector < pii > v;
map < int, int > mp;
int main(){
	int n, k, l;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}
	l = 0;
	k = 0;
	for(int i = 0 ; i < n ; i++){
		if(mp[a[i]] == 0){
			mp[a[i]] = i+1;
		}
		else{
			v.PB(MP(l+1, i+1));
			l = i+1;
			mp.clear();
			k++;
		}
	}
	if(k == 0){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", k);
	v[k-1].SS = n;
	for(int i = 0 ; i < v.size() ; i++){
		printf("%d %d\n", v[i].FF, v[i].SS);
	}
	return 0;
}