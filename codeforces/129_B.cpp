#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, *rem;
	list < int > *adj;
public:
	graph(int v_) : v(v_) {
		adj = new list < int > [v];
		rem = new int[v];
		for(int i = 0 ; i < v ; i++)
			rem[i] = 0;
	}
	void add_edge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int count_groups(){
		int cnt, f, temp;
		list < int > :: iterator it;
		cnt = f = 0;
		while(f == 0){
			for(int i = 0 ; i < v ; i++) {
				temp = 0;
				if(rem[i] == 1)
					continue;
				for(it = adj[i].begin() ; it != adj[i].end() ; it++){
					if(rem[*it] == 1)
						continue;
					temp++;
				}
				if(temp == 1){
					rem[i] = 2;
					f = 2;
				}
			}
			if(f == 2){
				cnt++;
				for(int i = 0 ; i < v ; i++){
					if(rem[i] == 2){
						rem[i] = 1;
					}
				}
				f = 0;
			}
			else
				f = 1;
		}
		return cnt;
	}
};
int main() {
	int n, e, x, y;
	scanf("%d%d", &n, &e);
	graph g(n);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		g.add_edge(x, y);
	}
	printf("%d\n", g.count_groups());
	return 0;
}