#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
	int k, *alpha, cnt;
	char *a = new char[101];
	scanf("%d", &k);
	scanf("%s", a);
	int n = strlen(a);
	alpha = new int[26];
	for(int i = 0; i < 26 ; i++)
		alpha[i] = 0;
	for(int i = 0; i < n ; i++){
		alpha[a[i]-'a'] = 1;
	}
	cnt =0 ;
	for(int i =0 ; i < 26 ; i++)
		cnt += alpha[i];
	if(cnt < k)
		printf("NO");
	else{
		printf("YES\n");
		for(int i = 0 ; i < 26 ; i++)
			alpha[i] = 0;
		printf("%c", a[0]);
		int j = 1;
		alpha[a[0]-'a'] = 1;
		for(int i = 1; i < n ; i++){
			if(alpha[a[i]-'a'] == 0 and j < k){
				alpha[a[i]-'a'] = 1;
				printf("\n%c", a[i]);
				j++;
			}
			else
				printf("%c", a[i]);
		}
	}
	return 0;
}