#include <iostream>
#include <stdio.h>
#define MAX 10001
using namespace std;
int main() {
	int n, *ev, *od, maxpos, max, f;
	char *s;
	s = new char[MAX];
	printf("Enter the string of length <= 10,000 letters :\n");
	scanf("%s", s);
	for(n = 0 ; s[n] != '\0' ; n++);
	ev = new int[n];
	od = new int[n];
	for(int i = 0 ; i < n-1 ; i++){
		if(s[i] == s[i+1])
			ev[i] = 2;
	}
	for(int i = 0 ; i < n-2 ; i++){
		if(s[i] == s[i+2])
			od[i] = 3;
	}
	f = 0;
	for(int k = 4 ; k < n ; k = k+2){
		for(int i = 1 ; i < n-k+2 ; i++){
			if(ev[i] == k-2 and s[i-1] == s[i+k-2]){
				ev[i-1] = k;
				f = 1;
			}
		}
		if(f == 0)
			break;
	}
	f = 0;
	for(int k = 5 ; k < n ; k = k+2){
		for(int i = 1 ; i < n-k+2 ; i++){
			if(od[i] == k-2 and s[i-1] == s[i+k-2]){
				od[i-1] = k;
				f = 1;
			}
		}
		if(f == 0)
			break;
	}
	cout << "ev : ";
	for(int i = 0 ; i < n ; i++)
		printf("%d ", ev[i]);
	cout << endl;
	cout << "od : ";
	for(int i = 0 ; i < n ; i++)
		printf("%d ", od[i]);
	cout << endl;
	maxpos = 0;
	max = ev[0];
	for(int i = 0 ; i < n ; i++){
		if(ev[i] > max){
			maxpos = i;
			max = ev[i];
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(od[i] > max){
			max = od[i];
			maxpos = i;
		}
	}
	if(max == 0){
		max = 1;
		maxpos = 0;
	}
	printf("Longest palindromic substring has length : %d\n", max);
	printf("And the substring is : ");
	for(int i = maxpos ; i < maxpos+max ; i++)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}