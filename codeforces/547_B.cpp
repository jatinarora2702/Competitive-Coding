#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main() {
	int n, *a, *l, *r, *p;
	scanf("%d", &n);
	a = new int[n];
	l = new int[n];
	r = new int[n];
	p = new int[n];
	stack < int > s;
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; i++){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(s.empty())
			l[i] = -1;
		else
			l[i] = s.top();
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i = n-1 ; i >= 0 ; i--){
		while(!s.empty() && a[s.top()] >= a[i])
			s.pop();
		if(s.empty())
			r[i] = n;
		else
			r[i] = s.top();
		s.push(i);
	}
	// for(int i = 0 ; i < n;  i++)
	// 	printf("%d ", l[i]);
	// printf("\n");
	// for(int i = 0 ; i  < n; i++)
	// 	printf("%d ", r[i]);
	// printf("\n");
	for(int i = 0 ; i < n ; i++)
		p[i] = 0;
	for(int i = 0 ; i < n ; i++){
		if(p[0] < a[i])
			p[0] = a[i];
		if(p[r[i]-l[i]-2] < a[i])
			p[r[i]-l[i]-2] = a[i];
	}
	for(int i = n-2 ; i >= 0 ; i--)
		p[i] = max(p[i], p[i+1]);
	for(int i = 0 ; i < n ; i++)
		printf("%d ", p[i]);
	return 0;
}