#include <iostream>
#include <stdio.h>
#include <deque>
#include <list>
using namespace std;
int fact(int n){
	int cnt = 1;
	for(int i = 2 ; i <= n ; i++)
		cnt *= i;
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	int n, k[2], x, x1, x2, cnt;
	deque < int > l[2];
	scanf("%d", &n);
	for(int i = 0 ; i < 2 ; i++){
		scanf("%d", &k[i]);
		for(int j = 0 ; j < k[i] ; j++){
			scanf("%d", &x);
			l[i].push_back(x);
		}
	}
	cnt = 39916800;
	// cnt = min(cnt, (int)1e5);
	// cout << fact(11) << endl;
	// cout << "cnt=" << cnt << endl;
	for(int i = 0 ; i < cnt ; i++){
		if(l[0].size() == 0){
			cout << i << " 2";
			return 0;
		}
		else if(l[1].size() == 0){
			cout << i << " 1";
			return 0;
		}
		x1 = l[0].front();
		x2 = l[1].front();
		// cout << x1 << " " << x2 << endl;
		l[0].pop_front();
		l[1].pop_front();
		if(x1 > x2){
			l[0].push_back(x2);
			l[0].push_back(x1);
		}
		else{
			l[1].push_back(x1);
			l[1].push_back(x2);	
		}
	}
	printf("-1");
	return 0;
}