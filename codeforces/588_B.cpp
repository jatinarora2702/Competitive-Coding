#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int a[N], pr[N];
typedef long long int lli;
int main() {
	lli n, p, k;
	a[0] = 1;
	a[1] = 1;
	pr[0] = 2;
	k = 1;
	for(int i = 4 ; i < N ; i += 2)
		a[i] = 1;
	for(int i = 3 ; i < N ; i += 2){
		if(a[i] == 0){
			// cout << i << endl;
			pr[k++] = i;
			for(int j = 2*i ; j < N ; j += i)
				a[j] = 1;
		}
	}
	// cout << k << endl;
	cin >> n;
	p = 1;
	for(int i = 0 ; i < k ; i++){
		if(n % (lli)pr[i] == 0){
			p *= pr[i];
			while(n % (lli)pr[i] == 0)
				n /= (lli)pr[i];
		}
	}
	p *= n;
	cout << p << "\n";
	return 0;
}