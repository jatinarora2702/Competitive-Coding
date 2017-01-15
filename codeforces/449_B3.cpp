#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>	
#define PATHINF 1000000000000000007
using namespace std;
int cnt;
typedef unsigned long long int ulli;
class graph{
	int v, f;
	list < pair < int, ulli > > *adj;
	list < pair < int, int > > *fadj;
	ulli *arr, *s;
	int *index, *visited;
	vector < pair < int, ulli > > heap;
public:
	graph(int v_, int f_) : v(v_), f(f_) {
		adj = new list < pair < int, ulli > > [v];
		fadj = new list < pair < int, int > > [v];
		if(f == 0){
			arr = new ulli[v];
			s = new ulli[v];
			index = new int[v];
			visited = new int[v];
			for(int i = 0 ; i < v ; i++)
				arr[i] = PATHINF;
			vector < pair < int, ulli > > vecx(v);
			for(int i = 0 ; i < v ; i++)
				vecx[i] = make_pair(i, PATHINF);
			heap = vecx;
			for(int i = 0 ; i < v ; i++)
				index[i] = i;
			for(int i = 0 ; i < v ;  i++)
				visited[i] = 0;
		}
	}
	void add_edge(int x, int y, ulli w, int flag){
		adj[x].push_back(make_pair(y, w));
		fadj[x].push_back(make_pair(y, flag));
		if(f == 0){
			adj[y].push_back(make_pair(x, w));
			fadj[y].push_back(make_pair(x, flag));
		}
	}
	void train_route(ulli *a){
		for(int i = 0 ; i < v ; i++)
			s[i] = a[i];
	}
	ulli* short_path(int src){
		pair < int, ulli > p;
		list < pair < int, ulli > > :: iterator it;
		arr[src] = 0;
		hmodify(src, 0);
		//printheap();
		//printf("index: "); printint(index, v);
		for(int i = 0 ; i < v ; i++){
			p = heap.front();
			//cout << "p=" << p.first << endl;
			hmodify(p.first, PATHINF);
			//printheap();
			//printf("index: "); printint(index, v);
			visited[p.first] = 1;
			arr[p.first] = p.second;
			for(it = adj[p.first].begin() ; it != adj[p.first].end() ; it++){
				if(visited[(*it).first] == 0 and arr[(*it).first] > (ulli)p.second + (ulli)(*it).second){
					arr[(*it).first] = (ulli)p.second + (ulli)(*it).second;
					hmodify((*it).first, arr[(*it).first]);
					//printheap();
					//printf("index: "); printint(index, v);
				}
			}
			//printf("arr: "); print(arr, v);
		}
		//print(arr, v);
		return arr;
	}
	void hmodify(int vtx, ulli new_val){
		int v1, v2, min;
		int k = index[vtx];
		//cout << "vtx=" << vtx << " k=" << k << endl;
		pair < int, ulli > p;
		if(heap[k].second > new_val){
			heap[k].second = new_val;
			while(k > 0 and heap[k].second < heap[(k-1)/2].second){
				//cout << "k=" << k << " (k-1)/2=" << (k-1)/2 << endl;
				v1 = heap[k].first;
				v2 = heap[(k-1)/2].first;
				//cout << "h[k]=" << v1 << " h[(k-1)/2]=" << v2 << endl;
				p = heap[k];
				heap[k] = heap[(k-1)/2];
				heap[(k-1)/2] = p;
				//index[heap[k].first] = (k-1)/2;
				index[v1] = (k-1)/2;
				index[v2] = k;
				k = (k-1)/2;
			}
		}
		else if(heap[k].second < new_val){
			//cout << "reached\n";
			heap[k].second = new_val;
			while(k < v){
				if(2*k+1 < v){
					min = 2*k+1;
					if(min+1 < v and heap[min].second > heap[min+1].second)
						min++;
					if(heap[k].second > heap[min].second){
						v1 = heap[k].first;
						v2 = heap[min].first;
						p = heap[k];
						heap[k] = heap[min];
						heap[min] = p;
						index[v1] = min;
						index[v2] = k;
						k = min;
					}
					else
						break;
				}
				else
					break;
			}
		}
	}
	void printint(int *a, int n){
		for(int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	void print(ulli *a, int n){
		for(int i = 0 ; i < n ; i++)
			cout << a[i] << " ";
		printf("\n");
	}
	void printheap(){
		printf("heap: ");
		for(int i = 0 ; i < v ; i++){
			cout << "[" << heap[i].first << " " << heap[i].second << "] ";
		}
		printf("\n");
	}
	void makegraph(){
		int v1, v2;
		ulli w;
		list < pair < int, ulli > > :: iterator it;
		list < pair < int, int > > :: iterator fit;
		int *vtxarray = new int[v];
		for(int i = 0 ; i < v ; i++)
			vtxarray[i] = 0;
		//print(arr, v);
		for(int i = 0 ; i < v ; i++){
			for(it = adj[i].begin(), fit = fadj[i].begin() ; it != adj[i].end() ; it++, fit++){
				v1 = i;
				v2 = (*it).first;
				w = (*it).second;
				//cout << "v1=" << v1 << " v2=" << v2 << " w=" << w << "f=" << (*fit).second << endl;
				if(arr[v1]+w == arr[v2]){
					if((*fit).second == 1){
						vtxarray[v2] = 1;
					}
				}
			}
		}
		//cout << "haha cnt=" << cnt << endl;
		for(it = adj[0].begin(), fit = fadj[0].begin() ; it != adj[0].end() ; it++, fit++){
			v1 = 0;
			v2 = (*it).first;
			w = (*it).second;
			if((*fit).second == 0){
				if(arr[v1]+w == arr[v2]){
					if(vtxarray[v2] != 0)
						cnt++;
				}
				else
					cnt++;
			}			
		}
	}
};
int main(){
	int n, m, r, x, y, w;
	ulli *a, *dis, *diswt;
	scanf("%d%d%d", &n, &m, &r);
	//graph g(n);
	graph gwt(n,0);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &x, &y, &w);
		x--; y--;
		//g.add_edge(x, y, w);
		gwt.add_edge(x, y, w, 1);
	}
	a = new ulli[n];
	for(int i = 0 ; i < n ; i++)
		a[i] = PATHINF;
	cnt = 0;
	for(int i = 0 ; i < r ; i++){
		scanf("%d%d", &x, &y);
		x--;
		if(a[x] != PATHINF){
			cnt++;
		}
		a[x] = ((ulli)y < a[x]) ? (ulli)y : a[x];
	}

	//cout << "cnt=" << cnt << endl;
	//g.train_route(a);
	gwt.train_route(a);
	//gwt.print(a, n);
	for(int i = 1 ; i < n ; i++){
		if(a[i] != PATHINF)
			gwt.add_edge(0, i, a[i], 0);
	}
	//dis = g.short_path(0);
	diswt = gwt.short_path(0);
	/*for(int i = 0 ; i < n ; i++){
		if(a[i] != PATHINF){
		 	if(a[i] > diswt[i])
				cnt++;
			else if(a[i] == diswt[i] and dis[i] == diswt[i])
				cnt++;
		}
	}*/
	graph g1(n,1);
	gwt.makegraph();
	printf("%d", cnt);
	return 0;
}