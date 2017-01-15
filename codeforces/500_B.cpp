#include<bits/stdc++.h>
using namespace std;

void merge(vector< int >& p ,int *a, int m,int  *b, int n, int *c) {
	int i,j,k;
	i = j = k = 0;
	while(i < m and j < n) {
		if(p[a[i]] < p[b[j]]) {
			c[k] = a[i];
			k++;
			i++;
		}
		else {
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while(i < m) {
		c[k] = a[i];
		i++;
		k++;
	}
	while(j < n) {
		c[k] = b[j];
		j++;
		k++;
	}
}
void mysort(vector < int >& p, int *v, int sz) {
	if(sz <= 1)
		return; 
	int m = sz / 2;
	mysort(p,v,m);
	mysort(p,v + m,sz-m);
	int *v1 = new int[sz];
	merge(p,v,m,v + m,sz-m,v1);
	for(int i = 0 ; i < sz ; i++ ) {
		v[i] = v1[i];
	}
}
void dfs_visit(char **s, int n , int i , vector < int >& v, vector < int >& visited) {
	v.push_back(i);
	visited[i] = 1;
	for(int j = 0 ; j < n ; j++ ) {
		if(i == j)
			continue;
		if(s[i][j] == '1' and visited[j] == 0) {
			dfs_visit(s,n,j,v,visited);
		}
	}
}

vector < vector < int > > dfs(char **s, int n) {
	vector < int > visited(n,0);
	vector < vector < int > > q;
	for(int i = 0 ; i < n ; i++ ) {
		if(visited[i] == 0) {
			vector < int > v;
			dfs_visit(s,n,i,v,visited);
			q.push_back(v);
		}
	}
	return q;
}

int main() {
	int n;
	scanf("%d",&n);
	vector < int > p(n);
	char **s = new char*[n];
	for(int i = 0 ; i < n ; i++ ) {
		scanf("%d",&p[i]);
	}
	for(int i = 0 ; i < n ; i++ ) {
		s[i] = new char[n+1];
		scanf("%s",s[i]);
	}
	vector < vector < int > > q = dfs(s,n);
	int **q1;
	q1 = new int*[q.size()];
	for(int i = 0 ; i < q.size() ; i++ ) {
		q1[i] = new int[q[i].size()];
		for(int j = 0 ; j < q[i].size() ; j++ ) {
			q1[i][j] = q[i][j];
		}
	}
	for(int i = 0 ; i < q.size() ; i++ ) {
		mysort(p,q1[i],q[i].size());
		sort(q[i].begin(),q[i].end());
	}
	vector < int > p1(n);
	for(int i = 0 ; i < q.size() ; i++ ) {
		for(int j = 0 ; j < q[i].size() ; j++ ) {
			p1[q[i][j]] = p[q1[i][j]];
		}
	}
	for(int i = 0 ; i < n ; i++ ) {
		printf("%d ",p1[i]);
	}
	return 0;
}
