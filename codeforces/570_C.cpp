#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, m, pos, *a, cnt;
	char *s, c;
	scanf("%d%d", &n, &m);
	s = new char[n+1];
	a = new int[n+1];
	scanf("%s", s);
	// printf("str=%s\n", s);
	cnt = 0;
	for(int i = 0 ; i <= n ; i++){
		a[i] = cnt;
		if(s[i+1] == '.')
			a[i]++;
		if(s[i] == '.')
			cnt = 1;
		else
			cnt = 0;
	}
	cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '.' && s[i+1] == '.')
			cnt++;
	}
	// printf("cnt=%d\n", cnt);
	// for(int i =  0 ; i < n ; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	for(int i = 0 ; i < m ; i++){
		scanf("%d %c", &pos, &c);
		pos--;
		if(c == '.' && s[pos] != '.'){
			s[pos] = '.';
			if(pos+1 < n) a[pos+1]++;
			if(pos-1 >= 0) a[pos-1]++;
			cnt += a[pos];
		}
		else if(c != '.' && s[pos] == '.'){
			s[pos] = c;
			cnt -= a[pos];
			if(pos+1 < n) a[pos+1]--;
			if(pos-1 >= 0) a[pos-1]--;
		}
		else
			s[pos] = c;
		printf("%d\n", cnt);
	}
	return 0;
}