#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
using namespace std;

typedef long long int lli;
typedef pair < int, int > pii;
vector < int > v;

void process(){
	int j = v.size()-1;
	while(j > 0){
		if(v[j-1] == v[j]){
			v[j-1] += 1;
			v.erase(v.begin()+j);
			j--;
		}
		else
			break;
	}
}
const int MOD = 1e9+7;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		v.PB(1);
		process();
	}
	for(int i = 0 ; i < v.size() ; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}