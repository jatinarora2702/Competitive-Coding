#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int *pi, i, j, n;
	while(true){
		cin >> s;
		if(s == "End")
			break;
		n = s.size();
		pi = (int*)malloc((n+1) * sizeof(int));
		pi[0] = 0;
		pi[1] = 0;
		for(i = 2 ; i <= n ; i++){
			j = pi[i-1];
			while(true){
				if(s[i-1] == s[j]){
					pi[i] = j+1;
					break;
				}
				if(j == 0){
					pi[i] = 0;
					break;
				}
				j = pi[j];
			}
		}
		for(int i = 1 ; i < n ; i++)
			printf("%d ", pi[i]);
		printf("%d\n", pi[n]);
	}
	return 0;
}