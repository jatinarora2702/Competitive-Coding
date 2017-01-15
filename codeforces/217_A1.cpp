#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
	vector < int > h;
	vector < int > v;
}comp;
int main(){
	int n, x, y, f;
	scanf("%d", &n);
	vector < comp > arr;
	comp *c;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &x, &y);
		f = 0;
		for(int j = 0 ; j < arr.size() ; j++){
			if(find(arr[j].h.begin(), arr[j].h.end(),x) != arr[j].h.end()){
				arr[j].v.push_back(y);
				f = 1;
			}
			else if(find(arr[j].v.begin(), arr[j].v.end(),y) != arr[j].v.end()){
				arr[j].h.push_back(x);
				f = 1;
			}
		}
		if(f == 0){
			c = new comp;		
			c->h.push_back(x);
			c->v.push_back(y);
			arr.push_back(*c);
		}
	}
	printf("%d", arr.size()-1);
	return 0;
}