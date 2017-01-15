#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N = 2000;
vector < pair < int, int > > vec(N);
bool slp(pair < int, int > p1, pair < int, int > p2, pair < int ,int > p3){
	if((p3.s - p2.s) * (p2.f - p1.f) == (p3.f - p2.f) * (p2.s - p1.s))
		return false;
	return true;
}
int main(){
	int n;
	long long int cnt;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d%d", &vec[i].f, &vec[i].s);
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			for(int k = j+1 ; k < n ; k++){
				bool p = slp(vec[i], vec[j], vec[k]);
				if(p) cnt++;
			}
		}
	}
	cout << cnt;
}