#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;
// handle k = 0 hashing case
int main(){
	int n, k, *a, b[N], v, *c, low;
	scanf("%d%d", &n, &k);
	a = new int[n];
	c = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < N ; i++)
		b[i] = -1;
	for(int i = 0 ; i < n ; i++)
		b[a[i]] = i;
	for(int i = n-1 ; i > 0 ; i--){
		low = -1;
		if(a[n-1] > k){
			f = 1;

			while()
		}
	}

}