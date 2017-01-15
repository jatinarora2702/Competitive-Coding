#include <iostream>
#include <stdio.h>
#include <cstring>
#define INF 1000000
using namespace std;
char s[105][105], alpha[26];
int main(){
	int n, *a, f, k, cnt, max, *arr, b;
	a = new int[26];
	for(int i = 0 ; i < 26 ; i++)
		a[i] = INF;
	scanf("%d", &n);
	arr = new int[n];
	for(int i = 0 ; i < n ; i++)
		arr[i] = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 101 ; j++)
			s[i][j] = '#';
	}
	max = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%s", s[i]);
		k = strlen(s[i]);
		if(max < k)
			max = k;
		s[i][k] = '#';
	}
	cnt = 0;
	f = 1;
	for(int i = 0 ; i < max ; i++){
		b = 1;
		for(int j = 0 ; j < n ; j++){
			if(arr[j] == 0 and b == 0 and s[j][i] == '#'){
				f = 0;
				break;
			}
			if(arr[j] == 0 and s[j][i] != '#'){
				b = 0;
				if(a[s[j][i]-'a'] > cnt){
					cnt++;
					arr[j] = 1;
					a[s[j][i]-'a'] = cnt;
				}
				else if(a[s[j][i]-'a'] < cnt){
					f = 0;
					break;
				}
				else
					arr[j-1] = 0;
			}
		}
		if(f == 0)
			break;
	}
	if(f == 0)
		printf("Impossible");
	else{
		for(int i = 0 ; i < 26 ; i++){
			if(a[i] != INF)
				alpha[a[i]-1] = 'a'+i;
		}
		for(int i = 0 ; i < 26 ; i++)
			a[i] = 0;
		for(int i = 0 ; i < cnt ; i++){
			printf("%c", alpha[i]);
			a[alpha[i]-'a'] = 1;
		}
		for(int i = 0 ; i < 26 ; i++){
			if(a[i] == 0)
				printf("%c", 'a'+i);
		}
	}
	return 0;
}