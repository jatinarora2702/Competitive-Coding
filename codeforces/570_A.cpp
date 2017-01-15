#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n, m, p, x, p_val;
	int a[101];
	for(int i =  0 ; i < 101 ; i++)
		a[i] = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		p_val = -1;
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &x);
			if(x > p_val){
				p_val = x;
				p = j;
			}
		}
		a[p]++;
	}
	p = 0;
	for(int i = 1 ; i < n ; i++){
		if(a[i] > a[p])
			p = i;
	}
	printf("%d", p+1);
	return 0;
}