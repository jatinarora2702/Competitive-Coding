#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 400
using namespace std;
typedef long long int lli;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 1e9+7;

int males[N], females[N], com[N];
int main(){
	int n, x, y, maxm;
	char ch;
	scanf("%d", &n);	
	for(int i = 0  ; i < n ; i++){
		scanf(" %c%d%d", &ch, &x, &y);
		if(ch == 'M'){
			for(int j = x ; j <= y ; j++){
				males[j]++;
			}
		}
		else{
			for(int j = x ; j <= y ; j++){
				females[j]++;
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		com[i] = min(males[i], females[i]);
	}
	maxm = 0;
	for(int i = 0 ; i < N ; i++){
		maxm = max(maxm, com[i]);
	}
	printf("%d\n", 2 * maxm);
	return 0;
}