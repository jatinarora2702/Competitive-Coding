#include <iostream>
#include <stdio.h>
#define MAX 100005
using namespace std;
void precompute(char *p, int *pi){
	int i, j, k;
	pi[0] = 0;
	i = 1;
	k = i-1;
	while(true){
		if(p[i] == '\0')
				break;
		j = pi[k];
		cout << "i=" << i << " j=" << j << " k=" << k << endl;
		if(p[i] == p[j]){
			pi[i] = j+1;
			k = i;
			i++;
			cout << "in1\n";
			continue;
		}
		else{
			k = pi[j];
			cout << "in2\n";
		}
		if(j == 0){
			pi[i] = 0;
			k = i;
			i++;
			cout << "in3\n";
		}
	}
}
bool kmp(char *s, char *p, int *pi){
	int j;
	j = 0;
	for(int i = 0 ; s[i] != '\0' ; i++){
		if(s[i] == p[j]){
			j++;
			if(p[j] == '\0')
				return true;
		}
		else{
			while(j > 0){
				j = pi[j-1];
				if(s[i] == p[j]){
					j++;
					break;
				}
			}
		}
	}
	return false;
}
int main() {
	bool f;
	int n, m, *pi;
	char *p, *s;
	p = new char[MAX];
	s = new char[MAX];
	pi = new int[MAX];
	printf("Enter the string : ");
	scanf("%s", s);
	printf("Enter the pattern to look for : ");
	scanf("%s", p);
	precompute(p, pi);
	// for(int i = 0 ; p[i] != '\0' ; i++)
	// 	printf("%d ", pi[i]);
	// printf("\n");
	f = kmp(s, p, pi);
	if(f == true)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}