#include <iostream>
#include <cstdio>
#define N 1000000
using namespace std;
char text[N], pat[N];
int p[N];
int main() {
	int n, m, j;
	printf("Enter the text string :\n");
	scanf("%s", text);
	printf("Enter the pattern string :\n");
	scanf("%s", pat);
	for(n = 0 ; text[n] != '\0' ; n++);
	for(m = 0 ; pat[m] != '\0' ; m++);
	int *lps = new int[m+1];
	printf("The matchings are :\n");
	p[0] = 0;
	for(int i =	1 ; i < m ; i++){
		j = p[i-1];
		while(j > 0 && pat[i] != pat[j])
			j = p[j];
		if(j > 0)
			p[i] = j+1;
		else
			p[i] = ((pat[i] == pat[0]) ? 1 : 0);
	}
	j = 0;
	for(int i = 0 ; i < n ; i++){
		if(text[i] == pat[j]){
			j++;
			if(j == m){
				j = p[j-1];
				printf("char no # %d\n", i-m+2);
			}
		}
		else
			j = p[j-1];
	}
	return 0;
}