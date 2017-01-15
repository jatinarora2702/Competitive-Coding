#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

#define PB push_back
#define MP make_pair
#define FF first
#define N 300005
using namespace std;
typedef long long int lli;
typedef long double ld;
const int INF = (int)(1e9+7);
const int MOD = (int)(1e9+7);

char s[N];
int main(){
	int n, val;
	lli cnt = 0;
	scanf("%s", s);
	n = strlen(s);
	for(int i = n-1 ; i >= 0 ; i--){
		if(s[i] == '0' || s[i] == '4' || s[i] == '8')
			cnt++;
		if(i+1 < n){
			val = 10 * (s[i]-'0') + (s[i+1]-'0');
			if(val % 4 == 0){
				cnt += (lli)(i+1);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
