#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int t, n, m, x, y, *a;
	double *d, area;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		d = new double[n];
		a = new int[n];
		for(int i = 0 ; i < n ; i++)
			a[i] = 0;
		vector < pair < int, int > > v[n];
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &m);
			for(int j = 0 ; j < m ; j++){
				scanf("%d%d", &x, &y);
				v[i].push_back(make_pair(x, y));
			}
		}
		area = 0;
		for(int i = 0 ; i < n ; i++){
			m = v[i].size();
			for(int j = 0 ; j < m-1 ; j++){
				area += (double)(v[i][j].first * v[i][j+1].second - v[i][j+1].first * v[i][j].second);
			}
			area += (double)(v[i][m-1].first * v[i][0].second - v[i][0].first * v[i][m-1].second);
			area /= 2;
			area = abs(area);
			d[i] = area;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				if(d[i] > d[j])
					a[i]++;
				else if(d[j] > d[i])
					a[j]++;
			}
		}
		for(int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
	}
	return 0;
}