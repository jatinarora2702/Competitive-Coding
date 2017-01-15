#include <iostream>
#include <stdio.h>
#include <vector>
#define INF 1000000007
using namespace std;
typedef unsigned long long int ulli;
int main(){
	//cout << INT_MAX << endl;;
	int n, max, min;
	ulli cntmax, cntmin;
	scanf("%d", &n);
	vector < int > a(n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	max = -INF;
	min = INF;
	for(int i = 0 ; i < n ; i++){
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
	cntmax = 0;
	cntmin = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == max)
			cntmax++;
		if(a[i] == min)
			cntmin++;
	}
	if(max == min){
		cout << "0 " << (ulli)((ulli)n * (ulli)(n-1)) / 2;
	}
	else{
		cout << max - min << " " << cntmax * cntmin;
	}
	return 0;
}