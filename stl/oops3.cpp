#include <bits/stdc++.h>
using namespace std;

// advantages of forward declaration understood from this example..

void fn1();

class clazz {
protected:
	int x;
public:
	clazz(int);
	void somefn();
};

class clazz1 {
protected:
	int x;
public:
	clazz1(int);
	// void somefn();
	void fn2();
};

class temp {
protected:
	int x, y;
public:
	temp(int, int);
	virtual void print() const;
	friend void fn1();
	friend class clazz;
	friend void clazz1::fn2();
};

clazz::clazz(int cx): x(cx) {};

void clazz::somefn() {
	temp t(4, 5);
	cout << "clazz: " << t.x << " + " << t.y << "\n";
}

clazz1::clazz1(int cx): x(cx) {};

// void clazz1::somefn() {	// gives compile time error (and should!) - because tries to access private members of a class that is not friend..
// 	temp t(4, 5);
// 	cout << "clazz1:somefn: " << t.x << " + " << t.y << "\n";	// should not work!
// }

void clazz1::fn2() {
	temp t(4, 5);
	cout << "clazz1:fn2: " << t.x << " + " << t.y << "\n";	// should work!
}

temp::temp(int tx, int ty): x(tx), y(ty) {};

void temp::print() const {
	cout << "(" << this->x << ", " << this->y << ")\n";
}

void fn1() {
	temp t(4, 5);
	cout << "fn1: " << t.x << " + " << t.y << "\n";	// should work!
}

int main() {
	// friend functions and classes
	
	fn1();

	clazz c(44);
	c.somefn();

	clazz1 c1(10);
	c1.fn2();

	return 0;
}
