#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, *a, p, k;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	p = 1;
	k = n-a[0];
	for(int i = 0 ; i < n ; i++){
		a[i] += (p * k);
		// cout << a[i] << " ";
		if(a[i] < 0) a[i] += n;
		a[i] %= n;
		// cout << a[i] << endl;
		p *= -1;
	}
	p = 1;
	for(int i = 0 ; i < n ; i++){
		if(a[i] != i){
			p = 0;
			break;
		}
	}
	if(p == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}