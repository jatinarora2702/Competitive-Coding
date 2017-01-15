#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	int a[2000], n, f, k;
	vector < vector < int > > r(2000);
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; i++){
		r[a[i]-1].push_back(i);
	}
	k = 1;
	for(int i = r.size()-1 ; i >= 0 ; i--){
		f = 0;
		for(int j = 0 ; j < r[i].size() ; j++){
			//cout << j << " " << i << " " << k << endl;
			f++;
			a[r[i][j]] = k;
		}
		k += f;
	}
	for(int i = 0 ; i < n ; i++)
		printf("%d ", a[i]);
	return 0;
}