#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
#define ss second
#define ff first
using namespace std;
typedef long long int lli;
int main(){
	int n, m, *a, k, *l, *r, j, x_v, n_new, mid, val, begin, end;
	pair < int, lli > *p, *b;
	char c, cc;
	lli x, sum;
	scanf("%d%d", &n, &m);
	a = new int[n];
	l = new int[n];
	r = new int[n];
	stack < int > s;
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; i++){
		while(!s.empty() && a[s.top()] <= a[i])
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
		while(!s.empty() && a[s.top()] < a[i])
			s.pop();
		if(s.empty())
			r[i] = n;
		else
			r[i] = s.top();
		s.push(i);
	}
	p = new pair < int, lli > [n];
	for(int i = 0 ; i < n ; i++){
		x = (lli)(r[i]-i) * (lli)(i-l[i]);
		// x = (x * (x+1)) / (lli)2;
		p[i] = make_pair(a[i], x);
	}
	sort(p, p+n);
	// for(int i = 0 ; i < n ; i++){
	// 	printf("(%d, %lld) ", p[i].ff, p[i].ss);
	// }
	b = new pair < int, lli > [n];
	j = 0;
	sum = 0;
	for(int i = 0 ; i < n ; i++){
		x = p[i].ss;
		x_v = p[i].ff;
		i++;
		while(i < n && p[i].ff == x_v){
			x += p[i].ss;
			i++;
		}
		sum += x;
		b[j] = make_pair(x_v, sum);
		j++;
		i--;
	}
	n_new = j;
	for(int i = 0 ; i < m ; i++){
		c = getchar();
		scanf("%c %d %c", &c, &k, &cc);
		// printf("a=%c|b=%d|c=%c|", c, k, cc);
		begin = 0;
		end = n_new-1;
		while(begin <= end){
			mid = (begin + end) / 2;
			if(k < b[mid].ff)
				end = mid-1;
			else if(k > b[mid].ff)
				begin = mid+1;
			else
				break;
		}
		if(c == '='){
			if(b[mid].ff == k){
				val = b[mid].ss;
				if(mid > 0)
					val -= b[mid-1].ss;
			}
			else
				val = 0;
		}
		else if(c == '>'){
			if(b[mid].ff != k)
				mid = min(begin, end);
			val = b[n_new-1].ss - b[mid].ss;
		}
		else if(c == '<'){
			if(b[mid].ff != k){
				mid = min(begin, end);
				val = b[mid].ss;
			}
			else{
				if(mid > 0)
					val = b[mid-1].ss;
				else
					val = 0;
			}
		}
		if(val % 2 == 0)
			printf("%c", (cc == 'D') ? 'C' : 'D');
		else
			printf("%c", cc);
	}
	return 0;
}