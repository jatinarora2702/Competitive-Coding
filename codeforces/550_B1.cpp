#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	vector < int > v;
	int n, l ,r, x, *c;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	c = new int[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &c[i]);
	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = v.size()-1 ; j >= 0 ; j--)
			v.push_back(c[i]+v[j]);
		v.push_back(c[i]);
	}
	
}