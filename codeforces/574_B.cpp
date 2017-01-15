#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, *a, *two, *three, *root, flag, k;
	scanf("%d", &n);
	a = new int[n];
	two = new int[n];
	three = new int[n];
	root = new int[n];
	for(int i= 0 ; i < n ; i++){
		two[i] = three[i] = 0;
	}
	for(int i = 0 ; i < n; i++){
		scanf("%d", &a[i]);
		k= a[i];

		while(k % 2 == 0){
			k /=2;
			two[i]++;
		}
		// cout << "k=" << k << endl;
		while(k % 3 == 0){
			k /= 3;
			three[i]++;
		}
		root[i] = k;
	}
	flag = 1;
	k = root[0];
	for(int i = 1 ; i < n; i++){
		if(root[i] != k){
			flag = 0;
			break;
		}
	}
	// for(int i = 0 ; i < n; i++){
	// 	cout << root[i] << " " << two[i] << " " << three[i] << endl;
	// }
	if(flag == 0)
		printf("No");
	else
		printf("Yes");
	return 0;
}