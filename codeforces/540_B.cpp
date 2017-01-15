#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n, k, p, x, y, *a, sum, rem, temp, pos, term;
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	a = new int[n];
	sum = 0;
	for(int i = 0 ;i < k ; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	temp = x - sum;
	if(sum + (n-k) > x)
		printf("-1");
	else{
		for(int i = k ; i < n ; i++){
			a[i] = 1;
		}
		temp = temp - (n-k);
		pos = k;
		/*for(int i = 0 ; i < n ; i++)
			cout << a[i] << " ";
		cout << endl;*/
		//cout << "temp=" << temp << endl;
		while(temp > 0 and pos < n){
			a[pos] = y;
			temp -= (y-1);
			if(temp < 0)
				a[pos] += temp;
			pos++;
		}
		int *b = new int[n];
		for(int i = 0 ; i < n ; i++)
			b[i] = a[i];
		sort(a, a+n);
		if(a[(n-1)/2] >= y){
			for(int i = k ; i < n ; i++){
				printf("%d ", b[i]);
			}
		}
		else
			printf("-1");
	}
	return 0;
}