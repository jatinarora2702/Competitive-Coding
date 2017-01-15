#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int n, **adj, **dist, *a;
	ulli sum;
	scanf("%d", &n);
	adj = new int*[n];
	dist = new int*[n];
	a = new int[n];
	for(int i = 0 ; i < n ; i++){
		adj[i] = new int[n];
		dist[i] = new int[n];
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &adj[i][j]);
			dist[i][j] = adj[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	for(int l = 0 ; l < n ; l++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				for(int k = 0 ; k < n ; k++){
					if(dist[i][k] != INF and dist[k][j] != INF)
						dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
		sum = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(dist[i][j] != INF)
					sum += (ulli)dist[i][j];
			}
		}
		cout << sum << " ";
		for(int i = 0 ; i < n ; i++){
			adj[a[l]][i] = INF;
			adj[i][a[l]] = INF;
		}
		adj[a[l]][a[l]] = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				dist[i][j] = adj[i][j];
	}
	return 0;
}