#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, f;
	f = 1;
	while(f != 0){
		scanf("%d", &n);
		printf("n=%d ~n=%d -~n=%d ~-n=%d\nenter f: ", n, ~n, -~n, ~-n);
		scanf("%d", &f);
	}
	return 0;
}