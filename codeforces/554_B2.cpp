#include <bits/stdc++.h>
using namespace std;
bool equals(char *a, char *b, int n){
	for(int i = 0 ; i < n ; i++)
		if(a[i] != b[i])
			return false;
	return true;
}
int main(){
	int n, max, cnt;
	char **s;
	scanf("%d", &n);
	s = new char*[n];
	for(int i = 0 ; i < n ; i++)
		s[i] = new char[n];
	for(int i = 0 ; i < n ; i++)
		scanf("%s", s[i]);
	max = 1;
	for(int i = 0 ; i < n-1 ; i++){
		cnt = 1;
		for(int j = i+1 ; j < n ; j++){
			if(equals(s[i], s[j], n))
				cnt++;
		}
		if(cnt > max)
			max = cnt;
	}
	printf("%d", max);
	return 0;
}