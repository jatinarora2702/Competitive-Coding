#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int x, y;
	node(){}
	node(int x_, int y_) : x(x_) , y(y_) {
	}
	int fn(int k){
		return x + y + k;
	}
};
struct cmp{
	int operator() (pair < node, int > &a, pair < node, int > &b){
		return (a.second < b.second);
	}
};
int main() {
	priority_queue < pair < node, int > , vector < pair < node , int > >, cmp > q;
	node n1(1,2);
	node n2(2,3);
	pair < node, int > p1, p2, r;
	p1 = make_pair(n1, 1);
	p2 = make_pair(n2, 2);
	q.push(p1);
	q.push(p2);

	r = q.top();
	q.pop();
	printf("returned : (%d, %d) : %d\n", r.first.x, r.first.y, r.second);
	r = q.top();
	q.pop();
	printf("returned : (%d, %d) : %d\n", r.first.x, r.first.y, r.second);
	
	return 0;
}