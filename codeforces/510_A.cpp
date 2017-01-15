#include <iostream>
#include <stdio.h>
#define N 50
using namespace std;
char s[N][N];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			s[i][j] = '.';
	for(int i = 0 ; i < n ; i+=2){
		for(int j = 0 ; j < m ; j++)
			s[i][j] = '#';
	}
	for(int i = 1 ; i < n ; i+=4)
		s[i][m-1] = '#';
	for(int i =  3 ; i < n ; i+=4)
		s[i][0] = '#';
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			printf("%c", s[i][j]);
		printf("\n");
	}
	return 0;
}