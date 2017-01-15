#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int vc[100001];
class graph{
	int v;
	vector < int > *adj;
public:
	graph(vector < int > &vec){
		v = vec.size();
		cout << "alalala\n";
		for(int i = 0 ; i < vec.size() ; i++)
			cout << vec[i] << endl;
		adj = new vector < int > [v];
		cout << "sz= " << adj->size();
		for(int i = 0 ; i < v ; i++){
			cout << "qq\n";
			adj[i].push_back(vec[i]);
		}
		cout << "APsz=" << adj->size();
		cout << "APAPA\n";
		for(int i = 0 ; i < adj->size() ; i++){
			cout << "QPQ\n";
			for(int j = 0 ; j < adj[i].size() ; j++)
				cout << adj[i][j] << " ";
			cout << endl;
		}
		cout << "lpwpwp\n";
	}
	void add_edge(int x, int y){
		if(vc[x] != vc[y]){
			for(int i = 0 ; i < adj->size() ; i++) {
				cout << "apapa\n";
				if(adj[i][0] == vc[x])
					adj[i].push_back(vc[y]);
				else if(adj[i][0] == vc[y])
					adj[i].push_back(vc[x]);
			}
		}
		for(int i = 0 ; i < adj->size() ; i++){
			for(int j = 0 ; j < adj[i].size() ; j++)
				cout << adj[i][j] << " ";
			cout << endl;
		}
			
	}
	int get_col(){
		int max;
		max = 0;
		for(int i = 1 ; i < adj->size() ; i++){
			if(adj[max].size() < adj[i].size())
				max = i;
			else if(adj[max].size() == adj[i].size() and adj[max][0] > adj[i][0])
				max = i;
		}
		printf("%d", adj[max][0]);
	}
};
/*int vc[100001];
vector < pair < int, int > > adj;
int main(){
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &vc[i]);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		if(vc[x] != vc[y]){
			if(find(adj[vc[x]].begin(), adj[vc[x]].end(), vc[y]) == adj[vc[x]].end())
				adj[vc[x]].push_back(vc[y]);
		}
	}
}*/
int main(){
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	vector < int > vect;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &vc[i]);
	}
	for(int i = 0 ; i < n ;  i++){
		if(find(vect.begin(), vect.end(), vc[i]) == vect.end())
			vect.push_back(vc[i]);
		cout << "qpq\n";
	}
	graph g(vect);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	g.get_col();
	return 0;
}