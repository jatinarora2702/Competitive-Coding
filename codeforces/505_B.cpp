#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v, e;
	list < pair < int, int > > *adj;
	list < pair < int, int > > *clrs;
public:
	graph(int v_, int e_) : v(v_), e(e_) {
		adj = new list < pair < int, int > > [v];
		clrs = new list < pair < int, int > > [e];
	}
	void add_edge(int x, int y, int w){
		adj[x].push_back(make_pair(y,w));
		adj[y].push_back(make_pair(x,w));
	}
	void dfs(){
		int k = 0;
		int *visited = new int[v];
		for(int c = 0 ; c < e ; c++){
			for(int i = 0 ; i < v ; i++)
				visited[i] = 0;
			for(int i = 0 ; i < v ; i++){
				if(visited[i] == 0){
					dfs_visit(i, visited, k, c);
					k++;
				}
			}
		}
	}
	void dfs_visit(int s, int *visited, int k, int c){
		visited[s] = 1;
		list < pair < int, int > > :: iterator it;
		for(it = adj[s].begin() ; it != adj[s].end() ; it++){
			if(visited[(*it).first] == 0 and (*it).second == c){
				clrs[(*it).second].push_back(make_pair(s,k));
				clrs[(*it).second].push_back(make_pair((*it).first,k));
				dfs_visit((*it).first, visited, k, c);
			}
		}
	}
	int findnum(int x, int y){
		int cnt, fx, fy, kx, ky;
		cnt = 0;
		list < pair < int, int > > :: iterator it;
		for(int i = 0 ; i < e ; i++){
			fx = fy = 0;
			for(it = clrs[i].begin() ; it != clrs[i].end() ; it++){
				if((*it).first == x) { fx = 1; kx = (*it).second; }
				else if((*it).first == y) { fy = 1; ky = (*it).second; }
				if(fx and fy)
					break;
			}
			if((fx and fy) and kx == ky)
				cnt++;
		}
		return cnt;
	}
	void print(){
		list < pair < int, int > > :: iterator it;
		for(int i = 0 ; i < v ; i++){
			printf("%d : ", i);
			for(it = clrs[i].begin() ; it != clrs[i].end() ; it++) {
				printf("[%d %d] ", (*it).first, (*it).second);
			}
			printf("\n");
		}
	}
};
int main(){
	int n, e, x, y, w, q, *arrx, *arry;
	scanf("%d%d", &n, &e);
	graph g(n, e);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d%d", &x, &y, &w);
		x--; y--; w--;
		g.add_edge(x, y, w);
	}
	g.dfs();
	scanf("%d", &q);
	arrx = new int[q];
	arry = new int[q];
	for(int i = 0 ; i < q ; i++){
		scanf("%d%d", &arrx[i], &arry[i]);
		arrx[i]--; arry[i]--;
	}
	for(int i = 0 ; i < q ; i++){
		printf("%d\n", g.findnum(arrx[i],arry[i]));
	}
	return 0;
}