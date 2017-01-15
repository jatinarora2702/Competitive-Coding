#include <iostream>
#include <cstdio>
#define N 100
using namespace std;
void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}
void permut_s(char *s, int l, int r){
	if(l == r){
		printf("%s\n", s);
		return;
	}
	for(int i = l ; i <= r ; i++){
		swap(s+l, s+i);
		permut_s(s, l+1, r);
		swap(s+l, s+i);
	}
}
int main(){
	int n;
	char s[N];
	printf("Enter a string : ");
	scanf("%s", s);
	for(n = 0 ; s[n] != '\0' ; n++);
	permut_s(s, 0, n-1);
	return 0;
}