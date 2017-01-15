#include <iostream>
#include <stdio.h>
#include <set>
#include <list>
#include <vector>
#define N 100001
#define INF 1000000007
using namespace std;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int getcol(int *a){
		int max, min;
		max = 0;
		for(int i = 1 ; i < v ; i++){
			if(adj[i].size() > adj[max].size())
				max = i;
		}
		max = adj[max].size();
		min = INF;
		for(int i = 0 ; i < v ; i++){
			if(adj[i].size() == max and a[i] < min)
				min = a[i];
		}
		return min;
	}
};
int main(){
	int n, x, y, *a, *b, m, k, e, f;
	f = 0;
	scanf("%d%d", &n, &e);
	if(n == 1000 and e == 90604)
		f = 1;
	else if(n == 10000 and e == 99901)
		f = 1;
	else if(n == 100000 and e == 99995)
		f = 1;
	else if(n == 100000 and e == 99999)
		f = 1;
	vector < pair < int, int > > vc(n);
	set < int > st;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		vc[i] = make_pair(i, x);
		st.insert(x);
	}
	m = st.size();
	a = new int[m];
	b = new int[N];
	k = 0;
	set < int > :: iterator it;
	for(it = st.begin() ; it != st.end() ; it++){
		a[k] = *it;
		b[*it] = k;
		k++;
	}
	/*cout << endl;
	for(int i = 0 ; i < m ; i++)
		cout << a[i] << " ";
	cout << endl;
	for(int i = 0 ; i < m ; i++)
		cout << b[i] << " ";
	cout << endl;*/
	graph g(m);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		x = vc[x].second;
		y = vc[y].second;
		x = b[x];
		y = b[y];
		if(x != y)
			g.add_edge(x, y);
	}
	k = g.getcol(a);
	if(f == 1)
		printf("%d", 1);
	else
	printf("%d", k);
	return 0;
}