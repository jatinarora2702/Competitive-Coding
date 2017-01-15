#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 200005
using namespace std;
typedef long long int lli;
int a[N];
int main(){
	int n, k, rem, i, n_new;
	lli sum, val;
	scanf("%d%d", &n, &k);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	sum = 0;
	rem = 0;
	i = 0;
	n_new = n;
	while(i < n_new){
		val = sum;
		if(i+rem < n)
			val -= (lli)((lli)a[i+rem] * (lli)i * (lli)(n_new-i-1));
		// cout << val << endl;
		if(val >= k){
			sum += (lli)a[i+rem] * (lli)i;
			i++;	
		}
		else{
			printf("%d\n", i+rem+1);
			rem++;
			n_new--;
		}
	}
	return 0;
}