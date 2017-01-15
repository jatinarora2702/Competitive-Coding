#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_);
	void add_edge(int x, int y);
	int* get_arti_pts();
	void dfs_visit(int *visited, int *dist, int *low, int *p, int *art, int s);
	void get_bconcomp(int *art);
	void dfs_visit_comp(int *visited, int *art, list < int > &stk, int s);
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y) {
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void graph::dfs_visit(int *visited, int *dist, int *low, int *p, int *art, int s) {
	int k = 0;
	visited[s] = 1;
	static int cnt = 0;
	dist[s] = low[s] = cnt;
	cnt++;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(visited[*it] == 0){
			k++;
			p[*it] = s;
			dfs_visit(visited, dist, low, p, art, *it);
			low[s] = min(low[*it], low[s]);
			if(k > 1 and p[s] == -1)
				art[s] = 1;
			else if(p[s] != -1 and low[*it] >= dist[s])
				art[s] = 1;
		}
		else{
			if(*it != p[s]){
				low[s] = min(dist[*it], low[s]);
			}
		}
	}
	visited[s] = 2;
}
int* graph::get_arti_pts(){
	int *low = new int[v];
	int *dist = new int[v];
	int *visited = new int[v];
	int *p = new int[v];
	int *art = new int[v];
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			p[i] = -1;
			dfs_visit(visited, dist, low, p, art, i);
		}
	}
	printf("Articulation pts. : ");
	for(int i = 0 ; i < v ; i++){
		if(art[i] == 1)
			printf("%d ", i);
	}
	printf("\n");
	return art;
}
void graph::dfs_visit_comp(int *visited, int *art, list < int > &stk, int s) {
	int f;
	visited[s] = 1;
	//cout << "s= "  << s << endl;
	stk.push_back(s);
	f = 1;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++) {
		//cout << "s=" << s << " *it = " << *it << endl;
		if(visited[*it] == 0){
			//cout << "apap\n";
			dfs_visit_comp(visited, art, stk, *it);
			//cout << "kk " << s << " " <<endl;
			if(art[s] == 1 and f == 1) {
				//cout << "yy\n";
				printf("Component : %d ", s);
				while(stk.back() != s){
					printf("%d ", stk.back());
					stk.pop_back();
				}
				printf("\n");
				f = 0;
			}
			//cout << "tt\n";
		}
		//cout << "qfqfqf\n";
		// might have to add an else
		else{
			if(*it != s and find(stk.begin(), stk.end(), *it) != stk.end())
				f = 0;
		}
	}
	//cout << "hh\n";
	visited[s] = 2;
}
void graph::get_bconcomp(int *art){
	list < int > stk;
	int *visited = new int[v];
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			//cout << "pp" << endl;
			dfs_visit_comp(visited, art, stk, i);
			//cout << "jsjsjsjsj\n";
			if(stk.size() > 0){
				cout << stk.size() << "aa";
				printf("Component : ");
				while(stk.size() > 0){
					printf("%d ", stk.back());
					stk.pop_back();
				}
				printf("\n");
			}
		}
	}
}
int main(){
	int v, e, x, y, *art;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &v, &e);
	graph g(v);
	printf("Enter the graph edges (u v) :\n");
	for(int i = 0 ; i < e ; i++) {
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	art = g.get_arti_pts();
	g.get_bconcomp(art);
	return 0;
}