#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
bool prime(int k){
	if(k == 2)
		return true;
	if(k % 2 == 0)
		return false;
	for(int i = 3 ; i <= sqrt(k) ; i = i+2){
		if(k % i == 0)
			return false;
	}
	return true;
}
int main(){
	int n, *a;
	ulli x;
	bool f;
	double y;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++) {
		cin >> x;
		if(x == 1)
			a[i] = 0;
		else{
			y = sqrt((long double)x);
			f = (ceilf(y) == y);
			if(f and prime(y))
				a[i] = 1;
			else
				a[i] = 0;
		}
	}
	for(int i = 0 ; i < n ; i++ ) {
		if(a[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}