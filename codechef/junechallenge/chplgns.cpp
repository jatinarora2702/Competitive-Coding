#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
int orient(pair < int, int > p1, pair < int, int > p2, pair < int , int > p3){
	int val = (p3.second - p2.second)*(p2.first - p1.first) - (p2.second - p1.second)*(p3.first - p2.first);
	if(val == 0) return 0;
	return (val < 0) ? -1 : 1;
}
int inside(vector < pair < int, int > > *v, int n, int x, int y){
	cout << "x=" << x << " y=" << y << endl;
	int o1, o2, o3, o4;
	int cnt = 0;
	pair < int, int > p = make_pair(INF, v[x][0].second);
	for(int i = 0 ; i < v[y].size()-1 ; i++){
		o1 = orient(v[x][0], p, v[y][i]);
		o2 = orient(v[x][0], p, v[y][i+1]);
		o3 = orient(v[y][i], v[y][i+1], v[x][0]);
		o4 = orient(v[y][i], v[y][i+1], p);
		if(((o1 != o2) and (o3 != o4)))
			cnt++;
	}
	if(cnt % 2 != 0)
		return 1;
	else{
		cnt = 0;
		p = make_pair(INF, v[y][0].second);
		for(int i = 0 ; i < v[x].size()-1 ; i++){
			o1 = orient(v[y][0], p, v[x][i]);
			o2 = orient(v[y][0], p, v[x][i+1]);
			o3 = orient(v[x][i], v[x][i+1], v[y][0]);
			o4 = orient(v[x][i], v[x][i+1], p);
			cout << "o:" << o1 << " " << o2 << " " << o3 << " " << o4 << endl;
			if(((o1 != o2) and (o3 != o4)))
				cnt++;
		}
		cout << "cnt=" << cnt << endl;
		if(cnt % 2 != 0)
			return -1;
		else return 0;
	}	
}
int main(){
	int t, n, m, x, y, *arr, k;
	vector < pair < int, int > > *v;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v = new vector < pair < int, int > > [n];
		arr = new int[n];
		for(int i = 0 ; i < n ; i++)
			arr[i] = 0;
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &m);
			for(int j = 0 ; j < m ; j++){
				scanf("%d%d", &x, &y);
				v[i].push_back(make_pair(x, y));
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				k = inside(v, n, i, j);
				cout << " ret : " << k << endl;
				if(k == 1)
					arr[i]++;
				else if(k == -1)
					arr[j]++;
			}
		}
		for(int i = 0 ; i < n ; i++)
			printf("%d ", arr[i]);
	}
	return 0;
}