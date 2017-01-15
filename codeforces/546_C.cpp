#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 40000000
using namespace std;
int main(){
	int n, k1, k2, i, f, k;
	scanf("%d", &n);
	scanf("%d", &k1);
	vector < int > a(k1);
	vector < int > :: iterator it;
	it = a.begin();
	for(i = 0 ; i < k1 ; i++){
		scanf("%d", &k);
		*it = k;
		it++;
	}
	scanf("%d", &k2);
	vector < int > b(k2);
	it = b.begin();
	for(i = 0 ; i < k2 ; i++){
		scanf("%d", &k);
		*it = k;
		it++;
	}
	f = 0;
	for(i = 0 ; i < MAX ; i++){
		if(a.size() == 0){
			f = 2;
			break;
		}
		else if(b.size() == 0){
			f = 1;
			break;
		}
		if(a.front() > b.front()){
			a.push_back(b.front());
			a.push_back(a.front());
			b.pop_front();
			a.pop_front();
		}
		else{
			b.push_back(a.front());
			b.push_back(b.front());
			a.pop_front();
			b.pop_front();
		}
	}
	if(f == 0)
		printf("-1");
	else
		printf("%d %d", i, f);
	return 0;
}