#include <bits/stdc++.h>
#define N 250001
using namespace std;
int chosen[N];
bool cmp(int a, int b){
	return a > b;
}
inline int gcd(int a, int b){
	int t;
	if(a < b){
		t = a;
		a = b;
		b = t;
	}
	while(b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
vector < int > v(N);
vector < int > :: iterator it;
int main() {
	int n, k, j, t, i;
	scanf("%d", &n);
	k = n * n;
	for(int i = 0 ; i < k ; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), cmp);
	j = 0;
	while(j < n){
		chosen[j++] = v[i];
		v.erase(v.begin());
		for(int l = 0 ; l < j-1 ; l++){
			t = gcd(chosen[j-1], chosen[l]);
			it = find(v.begin(),v.end(), t);
			v.erase(it);
			it = find(v.begin(),v.end(), t);
			v.erase(it);
		}
	}
	for(int i = 0 ;  i < n ; i++)
		printf("%d ", chosen[i]);
	return 0;
}