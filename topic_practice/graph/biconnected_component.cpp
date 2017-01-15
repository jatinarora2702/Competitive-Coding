#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_);
	void add_edge(int x, int y);
	void dfs_visit(int s, int *visited, int *p, int *disc, int *low, int *art);
	int* get_articulation_pts();
	void get_biconnected_comp();
	void dfs_visit_con(int s, int *visited, int *art, list < int > &seen, int *arti_visit);
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y) {
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void graph::dfs_visit(int s, int *visited, int *p ,int *disc, int *low, int *art) {
	int k = 0;
	static int c = 0;
	visited[s] = 1;
	disc[s] = low[s] = ++c;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[*it] == 0) {
			k++;
			p[*it] = s;
			dfs_visit(*it,visited,p,disc,low,art);
			low[s] = min(low[s],low[*it]);
			if(low[*it] >= disc[s] and p[s] != -1)
				art[s] = 1;
			else if(p[s] == -1 and k > 1)
				art[s] = 1;
		}
		else if(*it != p[s]){
			low[s] = min(disc[*it], low[s]);
		}
	}
}
int* graph::get_articulation_pts() {
	int *visited = new int[v];
	int *disc = new int[v];
	int *art = new int[v];
	int *low = new int[v];
	int *p = new int[v];
	for(int i = 0 ; i < v ; i++){
		p[i] = -1;
	}
	for(int i = 0 ; i < v ; i++) {
		if(visited[i] == 0){
			p[i] = -1;
			dfs_visit(i,visited,p,disc,low,art);
		}
	}
	printf("art : ");
	for(int i = 0 ; i < v ; i++){
		if(art[i] == 1)
			printf("%d ", i);
	}
	printf("\n");
	return art;
}
void graph::dfs_visit_con(int s, int *visited, int *art, list < int > &seen, int *arti_visit) {
	if(art[s] == 1 and arti_visit[s] == 0)
		arti_visit[s] = 1;
	cout << "s=" << s << " : ";
	for(typeof(seen.begin()) itt = seen.begin() ; itt != seen.end() ; itt++) {
		cout << *itt << " ";
	}
	cout << endl;
	seen.push_back(s);
	visited[s] = 1;
	list < int > :: iterator it;
	for(it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[*it] == 0){
			dfs_visit_con(*it,visited,art,seen,arti_visit);
		}
		else if(visited[*it] == 1){
			if(art[*it] == 1 and arti_visit[*it] == 1){
				printf("Component : %d ",*it);
				while(seen.back() != *it){
					printf("%d ",seen.back());
					seen.pop_back();
				}
				printf("\n");
			}
		}
	}
}
void graph::get_biconnected_comp(){
	int *visited = new int[v];
	int *arti_visit = new int[v];
	int *art = get_articulation_pts();
	list < int > seen;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == 0){
			dfs_visit_con(i,visited,art,seen,arti_visit);
			if(seen.size() != 0){
				printf("Component : ");
				while(seen.size() != 0){
					printf("%d ",seen.back());
					seen.pop_back();
				}
				printf("\n");
			}
		}
	}
}
int main() {
	int n, e, x, y;
	printf("Enter the no. of vertices and edges in the graph (v e) : ");
	scanf("%d%d", &n, &e);
	graph g(n);
	printf("Enter the graph edges (u v) :\n");
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	g.get_biconnected_comp();
	return 0;
}