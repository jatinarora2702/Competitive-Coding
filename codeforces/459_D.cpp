#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	vector < int > v(n);
	map < int, vector < int > > m;
	for(int i = 0 ; i < n; i++){
		scanf("%d", &v[i]);
		if(m.find(i))
			m[v[i]].push_back(i);
		else{
			vector < int > v1(1, i);
			m[v[i]] =  v1;
		}
	}
	
}