#include <bits/stdc++.h>
#define N 250001
using namespace std;
map < int, int > m;
map < int, int > :: iterator it;
int chosen[N];
int main(){
	int n, n_2, x, maxm, j, k;
	scanf("%d", &n);
	n_2 = n * n;
	maxm = 0;
	for(int i = 0 ; i < n_2 ; i++){
		scanf("%d", &x);
		if(maxm < x)
			maxm = x;
		m[x]++;
	}
	j = 0;
	while(j < n){
		it = m.end();
		it--;
		it->second--;
		chosen[j++] = it->first;
		if(it->second == 0)
			m.erase(it);
		for(int i = 0 ; i < j-1 ; i++){
			k = __gcd(chosen[i], chosen[j-1]);
			m[k] -= 2;
			if(m[k] == 0)
				m.erase(k);
		}
	}	
	for(int i = 0 ; i < n ; i++)
		printf("%d ", chosen[i]);
	return 0;
}