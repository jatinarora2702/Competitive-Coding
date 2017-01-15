#include <bits/stdc++.h>
#define N 250005
using namespace std;
multiset < int > sa;
vector < int > v;
bool cmp(int a, int b){
	return a > b;
}
int gcd(int a, int b){
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
int main() {
	int n, k, j, cnt, t, x, m;
	scanf("%d", &n);
	k = n * n;
	for(int i = 0 ; i < k ; i++){
		scanf("%d", &x);
		sa.insert(x);	
	}
	multiset < int > :: reverse_iterator it, it1;
	for(it = sa.rbegin() ; it != sa.rend() ; it++){
		v.push_back(*it);
		sa.erase(*it);
		it--;
		for(int i = 0 ; i < v.size()-1 ; i++){
			m = gcd(v[i], *it);
			sa.erase(m);
			it--;
			sa.erase(m);
			it--;
		}
	}
	for(int i = 0 ; i < v.size() ; i++)
		printf("%d ", v[i]);
	return 0;
}
