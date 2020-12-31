#include <bits/stdc++.h>
using namespace std;

enum temp1 {
	x, y, z
};

// enums are not allowed to be forward declared in c++!

enum temp {
	a = 'a', b = 'b', c = temp1::x
};	// automatically assigns c = 'c' (starts counting numbers from there..)

void fn(temp1&);

int main() {
	temp t1, t2, t3;
	int a;
	t1 = temp::a;	// t1 = a (does not work! - because of the variable name clash, otherwise, it works without the 'temp::' thing)
	t2 = temp::b;
	t3 = temp::c;
	cout << (char)t1 << "\n";
	cout << t2 << "\n";
	cout << t3 << "\n";


	temp1 tx = temp1::x;
	temp1 ty = (temp1)1;
	temp1 tz = temp1::z;
	temp1 tw = (temp1)19;

	fn(tx);
	fn(ty);
	fn(tz);
	fn(tw);

	return 0;
}

void fn(temp1& t) {
	switch(t) {
		case temp1::x:
			cout << "x\n";
			break;
		case temp1::y:
			cout << "y\n";
			break;
		case temp1::z:
			cout << "z\n";
			break;
		default:
			cout << "wrong!\n";
	}
}
