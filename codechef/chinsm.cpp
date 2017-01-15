#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lli;
int main(){
	int n, *a, k, *b, low, j;
	lli cnt;
	scanf("%d%d", &n, &k);
	a = new int[n];
	b = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	b[0] = 0;
	cnt = 1;
	for(int i = 1 ; i < n ; i++){
		low = 0;
		j = i-1;
		cnt++;
		while(j >= low){
			if(a[j] % a[i] == k){
				b[i] = j+1;
				break;
			}
			cnt++;
			low = max(low, b[j]);
			j--;
		}
		if(j < low)
			b[i] = low;
	}
	printf("%lld", cnt);
	return 0;
}