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

char s[N], s1[N];
int main(){
	int n, k, val1, val2;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0 ; i < n ; i++){
		val1 = s[i] - 'a';
		val2 = 'z' - s[i];
		//cout << val1 << " " << val2 << endl;
		if(val1 > val2){
			if(k < val1){
				s1[i] = s[i] - k;
				k = 0;
			}
			else{
				s1[i] = s[i] - val1;
				k -= val1;	
			}
		}
		else{
			if(k < val2){
				s1[i] = s[i] + k;
				k = 0;
			}
			else{
				s1[i] = s[i] + val2;
				k -= val2;	
			}
		}
	}
	s1[n] = '\0';
	if(k != 0)
		printf("-1\n");
	else
		printf("%s\n", s1);
}
