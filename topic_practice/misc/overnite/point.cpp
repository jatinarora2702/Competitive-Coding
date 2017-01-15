#include <bits/stdc++.h>
#define N 50005
using namespace std;
typedef struct {
	int x, y, z, index;
}pt;

bool fnx(pt p1, pt p2){
	return (p1.x < p2.x);
}

int* merge1(int *a1, int m, int *a2, int n, int *c){
	int i, j, k;
	i = j = k = 0;
	while(i < m && j < n){
		
	}
}

vector < int > findcnt(vector < pt > vp, int n){
	vector < int > vans, vans1, vans2;
	if(n == 1)
		ans.push_back(0);
		return ans;
	}
	int m = n / 2;
	vans1 = findcnt(vp, m);
	vans2 = findcnt(m+1, e);
	for(int i = b ; i <= e ; i++){
		v1
	merge1(a1, m-b+1, a2, e-m, a);
	return a;
}

int main(){
	int n, *ans;
	pt *a = new int[n];
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].z);
		v[i].index = i;
	}
	sort(v, v+n, fnx);
	ans = findcnt(v, n);
	for(int i = 0 ; i < n ; i++){
		printf("%d ", ans[i];
	}
	return 0;
}
