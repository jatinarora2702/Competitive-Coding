#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int t, n, m, *unlucky, skip, f;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		unlucky = new int[m];
		for(int i = 0 ; i < m ; i++)
			scanf("%d", &unlucky[i]);
		sort(unlucky, unlucky+m);
		if(unlucky[0] == 1 || unlucky[m-1] == n)
			f = 0;
		else{
			f = 1;
			for(int i = 0 ; i < m ; i++){
				skip = 1;
				i++;
				while(i < m && unlucky[i] - unlucky[i-1] == 1){
					skip++; i++;
				}
				i--;
				if(skip > 2){
					f = 0;
					break;
				}
			}
		}
		if(f == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}