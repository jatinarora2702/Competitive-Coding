#include <bits/stdc++.h>
using namespace std;

void fn1();
class clazz;

class temp {
protected:
	int x, y;
public:
	temp(int tx, int ty): x(tx), y(ty) {};
	virtual void print() const {
		cout << "(" << this->x << ", " << this->y << ")\n";
	}
	friend void fn1();
	friend class clazz;
};

class clazz {
protected:
	int x;
public:
	clazz(int cx): x(cx) {};
	void somefn() {
		temp t(4, 5);
		cout << "clazz: " << t.x << " + " << t.y << "\n";
	}
};

void fn1() {
	temp t(4, 5);
	cout << "fn1: " << t.x << " + " << t.y << "\n";	// should work!
}

int main() {
	// friend functions and classes
	
	fn1();

	clazz c(44);
	c.somefn();

	return 0;
}
