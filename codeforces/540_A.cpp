#include <iostream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main(){
	char *s1, *s2;
	int n, moves, temp;
	scanf("%d", &n);
	s1 = new char[n+1];
	s2 = new char[n+1];
	scanf("%s", s1);
	scanf("%s", s2);
	moves = 0;
	for(int i = 0 ; i < n ; i++){
		temp = abs((s1[i]-s2[i]));
		temp = min(temp, 10-temp);
		moves += temp;
	}
	printf("%d", moves);
	return 0;
}