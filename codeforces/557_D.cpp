#include <bits/stdc++.h>
#define N 100005
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
using namespace std;
typedef long long int lli;
vector < pair < int, int > > vec;
vector < int > g[N];
int v[N], even, odd, flag, fval[N];
void dfs(int s, int pr, int f){
	// printf("s=%d\n" , s);
	fval[s] = f;
	even += (f^1);
	odd += f;
	v[s] = 1;
	for(int i = 0 ; i < g[s].size() ; i++){
		// printf("child : %d\n", i);
		if(v[g[s][i]] && fval[g[s][i]] == f){
			flag = 1;
			return;
		}
		if(!v[g[s][i]] && (g[s][i] != pr)){
			dfs(g[s][i], s, f^1);
			if(flag)
				return;
		}
	}
}
int main(){
	int n, m, x, y, maxeven, maxodd;
	lli ans, k;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	// printf("graph: \n");
	// for(int i = 0 ; i < n ; i++){
	// 	printf("%d : ", i+1);
	// 	for(int j = 0 ; j < g[i].size() ; j++){
	// 		printf("%d ", g[i][j]+1);
	// 	}
	// 	printf("\n");
	// }
	flag = 0;
	for(int i = 0 ; i < n ; i++){
		if(!v[i]){
			even = 0;
			odd = 0;
			dfs(i, -1, 0);
			if(flag == 1){
				printf("0 1");
				return 0;
			}
			vec.PB(MP(even, odd));
			// for(int i = 0 ; i < n ; i++)
			// 	printf("%d ", v[i]);
			// cout << "\npp\n";
		}
	}
	// for(int i = 0 ; i < vec.size() ; i++){
	// 	printf("(%d, %d) ", vec[i].ff, vec[i].ss);
	// }
	// cout << endl;
	maxeven = 0;
	maxodd = 0;
	for(int i = 0 ; i < vec.size() ; i++){
		maxeven = max(maxeven, vec[i].ff);
		maxodd = max(maxodd, vec[i].ss);
	}
	if(maxeven == 1 && maxodd == 0){
		k = ((lli)n * (lli)(n-1) * (lli)(n-2)) / (lli)6;
		cout << "3 " << k;	
	}
	else if(maxeven == 1 && maxodd == 1){
		ans = 0;
		for(int i = 0 ; i < vec.size() ; i++){
			if(vec[i].ff == 1 && vec[i].ss == 1)
				ans += (lli)(n-2);
		}
		cout << "2 " << ans;
	}
	else{
		ans = 0;
		for(int i = 0 ; i < vec.size() ; i++){
			ans += (((lli)vec[i].ff * (lli)(vec[i].ff-1)) / (lli)2);
			ans += (((lli)vec[i].ss * (lli)(vec[i].ss-1)) / (lli)2);
		}
		cout << "1 " << ans;
	}
	return 0;
}