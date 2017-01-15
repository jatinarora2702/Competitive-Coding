#include <iostream>
#include <stdio.h>
#define MAX 4000001
using namespace std;
int main() {
	char *s = new char[MAX];
	int *pi, i, j, k;
	pi = new int[MAX];
	while(true){
		scanf("%s", s);
		if(s[0] == 'E' && s[1] == 'n' && s[2] == 'd' && s[3] == '\0')
			break;
		pi[0] = 0;
		i = 1;
		k = 0;
		while(true){
			j = pi[k];
			if(s[i] == s[j]){
				pi[i] = j+1;
				k = i;
				i++;
				if(s[i] == '\0')
					break;
			}
			else if(j > 0)
				k = pi[j];
			else{
				pi[i] = 0;
				k = i;
				i++;
				if(s[i] == '\0')
					break;
			}
		}
		for(int i = 0 ; s[i] != '\0' ; i++)
			printf("%d ", pi[i]);
		printf("\n");
	}
	return 0;
}