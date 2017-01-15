#include <iostream>
#include <stdio.h>
#define INF 1000000007
using namespace std;
typedef struct{
	int x,y;
}mypair;
int kadane(int *a, int n, int &r1, int &r2){
	int max, currmax;
	max = -INF;
	for(int i = 0 ; i < n ; i++){
		if(max < a[i]){
			max = a[i];
			r1 = r2 = i;
		}
	}
	if(max < 0)
		return max;
	else{
		max = currmax = 0;
		for(int i = 0 ; i < n ; i++){
			if(currmax == 0)
				r1 = i;
			currmax += a[i];
			if(currmax < 0)
				currmax = 0;
			else if(currmax > max){
				max = currmax;
				r2 = i;
			}
		}
		return max;
	}
}
int main() {
	int m, n, **a, **dp, *s, r1, r2, max, v;
	mypair p1, p2;
	printf("Enter the no. of rows and columns (r c) : ");
	scanf("%d%d", &m, &n);
	printf("Enter the 2d matrix :\n");
	a = new int*[m];
	for(int i = 0 ; i < m ; i++)
		a[i] = new int[n];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++)
			scanf("%d", &a[i][j]);
	}
	dp = new int*[m];
	for(int i = 0 ; i < m ; i++)
		dp[i] = new int[m];
	s = new int[n];
	max = -INF;
	for(int k = 0 ; k < m ; k++){
		for(int i = 0 ; i < m-k ; i++){
			for(int j = 0 ; j < n ; j++){
				s[j] = 0;
				for(int l = i ; l <= i+k ; l++){
					s[j] += a[l][j];
				}
			}
			v = kadane(s,n,r1,r2);
			/*
			cout << "f=" << i << " l=" << i+k << " r1=" << r1 << " r2=" << r2 << endl;
			for(int i1 = 0 ; i1 < n ; i1++)
				cout << s[i1] << " ";
			cout << endl;
			*/
			if(v > max){
				max = v;
				p1.x = i;
				p1.y = r1;
				p2.x = i+k;
				p2.y = r2;
			}
		}
	}
	printf("The max. sum rect. has sum : %d\n", max);
	printf("Co-ord. : (Top-Left) : (%d,%d) \t (Bottom-Right) : (%d,%d)\n", p1.x, p1.y, p2.x, p2.y);
	return 0;
}