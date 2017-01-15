#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
	return (a > b);
}
char N[100];
char M[400];
int main() {
	int t, d, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &d);
		scanf("%s", N);
		k = 0;
		for(int i = 0 ; i < d ; i++){
			if(N[i] > '1'){
				if(N[i] == '4'){
					M[k] = '2'; k++;
					M[k] = '2'; k++;
					M[k] = '3'; k++;
				}
				else if(N[i] == '6'){
					M[k] = '5'; k++;
					M[k] = '3'; k++;
				}
				else if(N[i] == '8'){
					M[k] = '2'; k++;
					M[k] = '2'; k++;
					M[k] = '2'; k++;
					M[k] = '7'; k++;	
				}
				else if(N[i] == '9'){
					M[k] = '7'; k++;
					M[k] = '2'; k++;
					M[k] = '3'; k++;
					M[k] = '3'; k++;
				}
				else{
					M[k] = N[i]; k++;
				}
			}
		}
		sort(M, M+k, cmp);
		M[k] = '\0';
		printf("%s\n", M);
	}
	return 0;
}