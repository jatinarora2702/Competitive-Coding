#include <iostream>
#include <stdio.h>
#define N 100001
using namespace std;
int main() {
	int t, *d;
	char *s, *sn;
	scanf("%d", &t);
	while(t--){
		s = new char[N];
		d = new int[26];
		scanf("%s", s);
		for(int n = 0 ; s[n] != '\0' ; n++);
		sn = new char[n+1];
		for(int i = 0 ; s[i] != '\0' ; i++){
			d[s[i]-'a']++;
		}
		mergesort(a,n,idx);
		for(int i = 0 ; i < n ; i++){
			
		}
	}
}