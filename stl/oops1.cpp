#include <bits/stdc++.h>
using namespace std;

class temp {
protected:
	int x, y;
public:
	temp(int tx, int ty): x(tx), y(ty) {};
	virtual void print() const {
		cout << "(" << this->x << ", " << this->y << ")\n";
	}
};

class temp1 : public temp {
protected:
	int z;
public:
	temp1(int tx, int ty, int tz): temp(tx, ty), z(tz) {};
	void print() const {
		cout << "(" << this->x << ", " << this->y << ", " << this->z << ")\n";
	}
};

class temp2 {
protected:
	int a, b;
public:
	temp2(int ta, int tb): a(ta), b(tb) {};
	void print() const {
		cout << "2(" << this->a << ", " << this->b << ")\n";
	}
};

class temp3: public temp1, public temp2 {
protected:
	int c;
public:
	temp3(int ta, int tb, int tc, int tx, int ty, int tz): temp1(tx, ty, tz), temp2(ta, tb), c(tc) {};
	void print() const {	// is this is not declared here, then, compile time error: call to print is ambiguous!
		cout << "3(" << this->a << ", " << this->b << ", " << this->c << ", " << this->x << ", " << this->y << ", " << this->z << ")\n";
	}
};

int main() {
	temp t(4, 5);
	t.print();

	temp1 t1(5, 6, 7);
	t1.print();

	temp* tp = new temp1(7, 8, 9);
	tp->print();	// if print is not made virtual in the 'temp' class, then temp::print is called, else, temp1::print is called.. (interesting!)

	temp2 t2(0, 1);
	t2.print();

	temp3 t3(1, 2, 3, 4, 5, 6);
	t3.print();

	temp* tp1 = new temp3(5, 6, 7, 8, 9, 10);	// since, temp::print is virtual here, so, best implementation picked.. even if temp1::print is not declared virtual
	tp1->print();

	temp2* tp2 = new temp3(2, 3, 4, 5, 6, 7);	// since, temp2::print is not virtual, we pick temp2::print here, not the latest one..
	tp2->print();

	return 0;
}
