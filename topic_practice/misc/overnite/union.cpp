// A union by rank and path compression based program to detect cycle in a graph
#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef struct{
	int uu, vv, ww;
}edgestr;
 
 edgestr arr[N];
 pair < int, int > r[N];
// a structure to represent an edge in graph
struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
struct subset
{
    int parent;
    int rank;
    int cnt;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
pair< int, int >  Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    pair<int, int> p = make_pair(subsets[xroot].cnt, subsets[yroot].cnt);
    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    	subsets[yroot].cnt += subsets[xroot].cnt;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
  		subsets[xroot].cnt += subsets[yroot].cnt;  
    }
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
      	subsets[xroot].cnt += subsets[yroot].cnt;
    }
    return p;
}
  
bool fn(edgestr a, edgestr b){
	return (a.ww > b.ww);
}

bool fn2(pair < long long, int > p1, pair < long long, int > p2){
	return (p1.second < p2.second);
}

// Driver program to test above functions
int main()
{
	int x, y, w;
    int V, E, q;
    scanf("%d%d%d", &V, &E, &q);
    struct Graph* graph = createGraph(V, E);
     	
 	for(int i = 0 ; i < E ; i++){
 		scanf("%d%d%d", &x, &y, &w);
 		graph->edge[i].src = x;
 		graph->edge[i].dest = y;
 		arr[i].uu = x;
 		arr[i].vv = y;
 		arr[i].ww = w;
 	}
 	
 	struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        subsets[v].cnt = 1;
    }
 	
 	for(int i = 0 ; i < q ; i++){
 		scanf("%d", &r[i].first);
 		r[i].second = i;
 	}
 	sort(arr, arr+E, fn);
 	sort(r, r+q);
 	pair < long long,  int > answer[q];
 	int k=q-1;
 	long long int sum = 0LL;
 	int flag = 1;
 	for(int i=0;i<E;i++)
 	{
 		if(arr[i].ww >= r[k].first)
 		{
 			flag = 1;
 			int src = arr[i].uu;
 			int dst = arr[i].vv;
 			int x = find(subsets,src);
 			int y = find(subsets,dst);
 			if(x == y){
 				
 				continue;
 			
 			}
 			else
 			{
 				pair <int, int> p = Union(subsets,x,y);
 				//printf("(%d %d)\n",p.first,  
 				sum = sum + (long long)p.first * (long long)p.second;
 				
 			}
 		}
 		else
 		{
 			while(k > 0 && r[k].first == r[k-1].first){
	 			answer[k].first = sum;
	 			answer[k].second = r[k].second;
	 			flag = 0;
	 			k--;
 			}
 			answer[k].first = sum;
 			answer[k].second = r[k].second;
 			flag = 0;
 			k--;
 			i--;
 		}
 		if(k < 0)
 			break;
 	}
 
 	if(flag == 1){
 		while(k >= 0){
	 		answer[k].first = sum;
	 		answer[k].second = r[k].second;
 			k--;
 		}
 	}
 		
 	sort(answer, answer+q, fn2);
 	for(int i = 0 ; i < q ; i++)
 		printf("%lld ", answer[i].first);
 	printf("\n");
 	return 0;
}
