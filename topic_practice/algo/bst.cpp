#include <bits/stdc++.h>
using namespace std;

class node {
	int v;
	node *l, *r;

public:
	node(int v);

	static node* ins(node *n, int x);

	static node* del(node *n, int x) {
		if (n == NULL) {
			return n;
		}
		if (x == n->v) {
			if (n->l == NULL && n->r == NULL) {
				delete n;
				return NULL;
			}
			else if (n->l == NULL) {
				node *t = n->r;
				delete n;
				return t;
			}
			else if (n->r == NULL) {
				node *t = n->l;
				delete n;
				return t;
			}
			else {
				node *t = n->r;
				if (t->l == NULL) {
					n->v = t->v;
					n->r = t->r;
					delete t;
					return n;
				}
				node *tp = n;
				while(t->l != NULL) {
					tp = t;
					t = t->l;
				}
				n->v = t->v;
				tp->l = t->r;
				delete t;
				return n;
			}
		}
		else if (x < n->v) {
			n->l = del(n->l, x);
		}
		else {
			n->r = del(n->r, x);
		}
		return n;
	}

	node* successor() {
		if (this->r == NULL) {
			return NULL;
		}
		node* n = this->r;
		while(n->l != NULL) {
			n = n->l;
		}
		return n;
	}

	void print();

	// bool operator>(const node& n) const {
	// 	return this->v > n.v;
	// }

	bool operator<(const node& n) const;
};

node::node(int v): v(v), l(NULL), r(NULL) {};

bool node::operator<(const node& n) const {
	return this->v < n.v;
}

node* node::ins(node *n, int x) {
	node* t = new node(x);
	if (n == NULL) {
		n = t;
		return n;
	}
	if (x < n->v) {
		n->l = node::ins(n->l, x);
	}
	else if (x > n->v) {
		n->r = node::ins(n->r, x);
	}
	return n;
}

void node::print() {
	cout << this->v << "\n";
	if (this->l != NULL) {
		this->l->print();
	}
	if (this->r != NULL) {
		this->r->print();
	}
}

int main() {
	// node *n1 = new node(2);
	// node::ins(n1, 1);
	// node::ins(n1, 4);
	// node::ins(n1, 3);
	// node::ins(n1, 5);
	// node::del(n1, 4);
	// n1->print();

	// priority_queue<node, vector<node>, greater<node>> pq;
	priority_queue<node, vector<node>, less<node>> pq;

	node a(2), b(3), c(4);
	pq.push(a);
	pq.push(b);
	pq.push(c);

	node k = pq.top();
	k.print();
	return 0;
}