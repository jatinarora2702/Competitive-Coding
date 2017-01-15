#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#define MAX 100005
using namespace std;
int main(){
	int n, e, x, y, max;
	scanf("%d%d", &n, &e);
	vector < int > c(n);
	vector < set < int > > adj(MAX);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &c[i]);
		adj[c[i]].insert(c[i]);
	}
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		adj[c[x]].insert(c[y]);
		adj[c[y]].insert(c[x]);
	}
	max = 0;
	/*for(int i = 0 ; i < 14 ; i++){
		set < int > :: iterator it;
		cout << adj[i].size() << " : " << endl;
		for(it = adj[i].begin() ; it != adj[i].end() ; it++)
			cout << *it << " ";
		cout << endl;
	}*/
	for(int i = 1 ; i < MAX ; i++){
		if(adj[i].size() > adj[max].size())
			max = i;
	}
	cout << max;
	return 0;
}