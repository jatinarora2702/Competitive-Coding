#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
int main(){
	int n, l, r, x, *c, cnt, max, min, sum, k;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	c = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &c[i]);
	cnt = 0;
	for(int i = 0 ; i < (1 << n) ; i++){
		sum = 0;
		max = 0;
		min = INF;
		k = 0;
		for(int j = 0 ; j < n ; j++){
			if(i & (1 << j)){
				sum += c[j];
				if(c[j] < min)
					min = c[j];
				if(c[j] > max)
					max = c[j];
				k++;
			}
		}
		//cout << sum << " " << max << " " << min << endl;
		if(sum >= l and sum <= r and max-min >= x and k >= 2)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}