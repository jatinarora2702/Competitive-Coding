#include <bits/stdc++.h>
#define N 200005
#define ff first
#define ss second
using namespace std;
int arr[N];
pair < pair < int, int > , int > p[N], ps, pbef;
set < pair < pair < int , int > , int > > s;
typedef struct{
	int start, end, extra;
}pair_struct;
typedef struct cmp_lb1{
	bool operator()(const pair < pair < int , int > , int > &a, const pair < pair < int ,int > , int > &b){
		if(a.ff.ff <= b.ff.ff && a.ff.ss >= b.ff.ss)
			return true;
	}
}cmp_lb;
// set < pair_struct > s;
int main() {
	int n, k, a, m, cnt;
	scanf("%d%d%d%d", &n, &k, &a, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d", &arr[i]);
	}
	// ps.ff.ff = 0;
	// ps.ff.ss = n-1;
	// ps.ss = ps.ff.ss - ((a+1) * k) + 1;
	// s.insert(ps);
	s.insert(make_pair(make_pair(2, 4), 3));
	s.insert(make_pair(make_pair(5, 7), 2));
	s.insert(make_pair(make_pair(8, 12), 1));
	s.insert(make_pair(make_pair(1, 1), 10));
	set < pair < pair < int , int > , int > > :: iterator it; 
	for(int i = 0 ; i < m ; i++){
		ps = make_pair(make_pair(arr[i], arr[i]), 1);
		lower_bound(s.begin(), s.end(), pbef, cmp_lb);
		if(it != s.end()){
			pbef = *it;
			printf("((%d, %d), %d)\n", pbef.ff.ff, pbef.ff.ss, pbef.ss);
		}
		else{
			printf("qq\n");
		}
	}
	return 0;
}