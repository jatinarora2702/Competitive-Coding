#include <bits/stdc++.h>
using namespace std;

// diff. between a struct and a class is that everything is private by default for classes, public for structs
struct Temp {
	int x, y;
};	// this ; is super imp!

Temp fn(Temp);	// prototype	// also checked pass by value mechanism

class MyClass {
	int a, b;
public:
	MyClass(int, int);	// not inlining the functions
	~MyClass();	// explicit destructor
	// also check how the .h thing works.. (imp. from the design perspective!) - ppd sir taught us, I guess.
	static MyClass fn1(MyClass&);	// checking how to work with static functions (also, checking pass by ref.) (done)
	// static MyClass fn1(MyClass);	// checking function overloading with ref. operator only change (supported.. normal calling fn. leads to ambiguous call.. not a good design.. (as per stackoverflow))
	// static MyClass fn1(MyClass*);	// checking function overloading with pointer operator only change (works!)
	static MyClass& fn1(MyClass*);	// checking function overloading with pointer operator change and return by ref.
	// static MyClass& fn1(MyClass&);	// also works exactly as the above one..
	void print();	// checking how to work with normal member functions (done)
	
	static MyClass fn1(MyClass&, int x);
	// static int fn1(MyClass&);	// is not valid overloading! (does not work!)

	// check function overloading (done)

	// check op overloading (and use in sort etc.) (done)
	// check stl with these objects (done)
	// check stl with obj pointers, obj ref. (done)
};

int main() {
	Temp t;
	t.x = 1;
	t.y = 2;
	cout << "addr1a:" << &t << "\n";	// sends a copy of object, not reference!
	Temp t1 = fn(t);
	cout << "addr2:" << &t1 << "\n";	// during return too.. returns a copy!
	cout << "struct:" << t1.x << " " << t1.y << "\n";

	MyClass c(4, 4);
	c.print();
	cout << "c:addr:" << &c << "\n";

	MyClass c1 = MyClass::fn1(c);	// cool! this is the way you call static member functions of a class
	cout << "c:addr:from_return:" << &c1 << "\n";	// wow! this is the same as the object that was passed in! (even though the return *does not* have MyClass&)

	c1.print();

	int x = 5;
	cout << "x:addr:" << &x << "\n";
	MyClass c2 = MyClass::fn1(c, x);	// checked function overloading with params change (also have to check with return type change - and with small changes like pointer/ref change only too)
	c2.print();

	// does not work (function overloading on return type change only.. does not work!)
	// int k = MyClass::fn1(c);
	// cout << k << "\n";

	// MyClass::fn1(c);	// leads to ambiguous call (for: fn1(MyClass&), fn1(MyClass)).. can be resolved by static_cast (of the function - c++ supports this.. but is not a good design.. works with pointers though)

	// MyClass c3 = MyClass::fn1(&c);	// wow! in this case, a copy during return is created!
	// cout << "c:addr:" << &c << "\n";
	// cout << "c3:addr:" << &c3 << "\n";
	// c3.print();
	// c.print();

	MyClass c4 = MyClass::fn1(&c);	// wow! *even* in this case, a copy during return is created!
	cout << "c:addr:" << &c << "\n";
	cout << "c4:addr:" << &c4 << "\n";
	c4.print();
	c.print();	

	cout << "calling destruct!\n";
	c.~MyClass();
	cout << "calling destruct done!\n";

	c.print();	// strangely, I still get the value here.. could be by chance I guess.. may be garbage too.. not sure..

	return 0;
}

Temp fn(Temp t) {
	Temp t1;
	cout << "addr2a:" << &t << "\n";	// sends a copy of object, not reference!
	t1.x = t.x + 1;
	t1.y = t.y + 1;
	cout << "addr1:" << &t1 << "\n";	// during return too.. returns a copy!
	return t1;
}

MyClass::MyClass(int a_, int b_): a(a_), b(b_) {};

MyClass MyClass::fn1(MyClass& c) {	// shouldn't write the static keyword here now.. (only write during declaration)
	cout << "fn1:addr:" << &c << "\n";	// pass by reference working! (no extra copy created..)
	c.a++;
	c.b++;
	return c;	// wow! i thought that since in the return statement, i don't have the & symbol.. so, a new copy of the object would be created..
	// but, thats not the case! i still get back the same object!
}

// MyClass MyClass::fn1(MyClass* c) {
// 	cout << "function overloading check with only pointer operator change\n";
// 	cout << "address:inp:" << c << "\n";
// 	c->a++;
// 	c->b++;
// 	return *c;	// during return a copy of the object is created!!
// }

MyClass& MyClass::fn1(MyClass* c) {
	cout << "function overloading check with only pointer operator change, return type ref.\n";
	cout << "address:inp:" << c << "\n";
	c->a++;
	c->b++;
	return *c;	// during return a copy of the object is created!! (even in this case!)
}

// MyClass MyClass::fn1(MyClass c) {	// checking fn. overloading with only ref operator change in params // not a good design.. leads to ambiguous call
// 	cout << "function overloading check with only ref. operator change\n";
// 	c.a++;
// 	c.b++;
// 	return c;
// }

void MyClass::print() {
	cout << "obj:" << this->a << " " << this->b << "\n";
}

MyClass MyClass::fn1(MyClass& c, int x) {
	cout << "x:addr:fn1:" << &x << "\n";	// so, even for primitive data types.. a copy is created when passed by value! (this value's address is diff.. from the one passed)
	c.a += x;
	c.b += x;
	return c;
}

MyClass::~MyClass() {
	cout << "destructor invoked " << this->a << " " << this->b << "!\n";
}

// int MyClass::fn1(MyClass& c) {	// checking overloading with only return type change (does not work!)
// 	cout << "fn overloading with return type diff\n";
// 	return c.x + c.y;
// }

