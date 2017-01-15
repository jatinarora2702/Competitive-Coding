#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
bool cmp(int a, int b){
	return (a > b);
}
int main() {
	int n, *a1, *a2, x, y, sum, i1, i2, n1, n2;
	ulli *cost, c1, c2;
	scanf("%d", &n);
	a1 = new int[n];
	a2 = new int[n];
	cost = new ulli[2*n+1];
	sum = i1 = i2 = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		sum += x;
		if(x == 1)
			a1[i1++] = y;
		else
			a2[i2++] = y;
	}
	n1 = i1;
	n2 = i2;
	sort(a1, a1+n1,cmp);
	sort(a2, a2+n2, cmp);
	for(int i = 0 ; i < n1 ; i++)
		cout << a1[i] << " ";
	cout << endl;
	for(int i = 0 ; i < n2 ; i++)
		cout << a2[i] << " ";
	cout << endl;
	i1 = i2 = 0;
	cost[0] = 0;
	for(int i = 1 ; i <= sum ; i++){
		c1 = c2 = 0;
		if(i1 < n1)
			c1 = cost[i-1] + (ulli)a1[i1];
		if(i2 < n2 and i-2 >= 0)
			c2 = cost[i-2] + (ulli)a2[i2];
		cout << "c1=" << c1 << " c2=" << c2 << endl;
		if(c1 > c2){
			cost[i] = c1;
			i1++;
		}
		else{
			cost[i] = c2;
			i2++;
		}
	}
	for(int i = 1 ; i <= sum ; i++){
		cout << cost[i] << " ";
	}
	return 0;
}