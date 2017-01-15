#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
int main(){
	int n, k, k1, sum, k2;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; i++){
		if(k == 0)
			break;
		k1 = a[i] / 10;
		k1 *= 10;
		if(k1 < a[i])
			k1 += 10;
		k1 = k1 - a[i];
		k2 = k - k1;
		// cout << k1 << " " << k2 << endl;
		if(k2 >= 0){
			a[i] += k1;
			k-=k1;
		}
		else{
			a[i] += k;
			k = 0;
		}
	}
	// cout << "pp\n";
	// for(int i = 0 ; i < n;  i++)
	// 	printf("%d ", a[i]);
	// printf("\n");
	for(int i = 0 ; i < n ; i++){
		if(k == 0)
			break;
		k1 = 100 - a[i];
		if(k1 <= k){
			k -= k1;
			a[i] = 100;
		}
		else{
			a[i] += k;
			k = 0;
		}
	}
	sum = 0;
	for(int i = 0 ; i < n;  i++)
		sum += (a[i] / 10);
	printf("%d", sum);
	return 0;
}