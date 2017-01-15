#include <iostream>
#include <stdio.h>
#include <list>
#define NIL -1
using namespace std;
class graph{
	int v;
	list < int > *adj;
public:
	graph(int v_);
	void add_edge(int x, int y);
	void get_atriculation_pts();
	void dfs_visit(int s, bool visited[], int p[], int disc[], int low[], bool art[]);
};
graph::graph(int v_) : v(v_) {
	adj = new list < int > [v];
}
void graph::add_edge(int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
/*
void graph::dfs_visit(int s, int *visited, int *p, int *disc, int *low, int *art, int c) {
	int k = 0;
	visited[s] = 1;
	disc[s] = low[s] = c;
	for(typeof(adj[s].begin()) it = adj[s].begin() ; it != adj[s].end() ; it++) {
		if(visited[*it] == 0){
			k++;
			p[*it] = s;
			dfs_visit(*it,visited,p,disc,low,art,c+1);
			low[s] = min(low[s],low[*it]);
			if(p[s] != -1 and low[*it] > disc[s])
				art[s] = 1;
			if(p[s] == -1 and k > 1)
				art[s] = 1;
		}
		else if(*it != p[s]){
			low[s] = min(low[s],disc[*it]);
		}
	}
}
*/
void graph::dfs_visit(int u, bool visited[], int parent[],int disc[], 
                                      int low[],  bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            dfs_visit(v, visited,parent, disc, low, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1){
                //cout << u << "--" << v << endl;
               ap[u] = true;
            }
 
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] > disc[u]){
                //cout << u << "--" << v << endl;
               ap[u] = true;
            }
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
void graph::get_atriculation_pts(){
	int k;
	bool *visited = new bool[v];
	int *p = new int[v];
	int *disc = new int[v];
	int *low = new int[v];
	bool *art = new bool[v];
    for(int i = 0 ; i < v ; i++)
        p[i] = -1;
	for(int i = 0 ; i < v ; i++){
		if(visited[i] == false){
			p[i] = -1;
			dfs_visit(i,visited,p,disc,low,art);
		}
	}
	k = 0;
	for(int i = 0 ; i < v ; i++){
		if(art[i] == 1)
			k++;
	}
	printf("There are %d articulation points :\n", k);
	for(int i = 0 ; i != v ; i++){
		if(art[i] == 1)
			printf("%d ", i);
	}
	printf("\n");
}
/*
// GIVEN ON GEEKS FOR GEEKS
// A C++ program to find articulation points in a given undirected graph
#include<bits/stdc++.h>
#include <list>
#define NIL -1
using namespace std;
 
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void APUtil(int v, bool visited[], int disc[], int low[], 
                int parent[], bool ap[]);
public:
    Graph(int V);   // Constructor
    void add_edge(int v, int w);   // function to add an edge to graph
    void AP();    // prints articulation points
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void Graph::APUtil(int u, bool visited[], int disc[], 
                                      int low[], int parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
 
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // To store articulation points
 
    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
 
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
    // Now ap[] contains articulation points, print them
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
}
 
// Driver program to test above function
*/
int main() {
	int n, e, x, y;
	printf("Enter the no. of vertices and edges in the undirected graph (v e) : ");
	scanf("%d%d", &n, &e);
	printf("Enter graph edges (u v) :\n");
	graph g(n);
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d", &x, &y);
		g.add_edge(x,y);
	}
	g.get_atriculation_pts();
	return 0;
}