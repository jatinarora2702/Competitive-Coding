#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 1000000007
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int **adj, n, *a, val;
	ulli sum;
	scanf("%d", &n);
	adj = new int*[n];
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
		adj[i] = new int[n];
		for(int j = 0 ; j < n ; j++)
			scanf("%d", &adj[i][j]);
	}
	sum = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	for(int i = 0 ; i < n ; i++){
		sum = 0;
		for(int j = 0 ; j < n ; j++){
			for(int k = j+1 ; k < n ; k++){
				val = min(adj[j][k], adj[k][j]);
				if(val != INF)
					sum += val;
			}
		}
		cout << sum << " ";
		for(int j = 0 ; j < n ; j++){
			adj[a[i]][j] = INF;
			adj[j][a[i]] = INF;
		}
	}
	return 0;
}