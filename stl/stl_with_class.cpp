#include <bits/stdc++.h>
using namespace std;

class Temp {
	int x, y;
public:
	Temp(int, int);
	void print();
};

Temp::Temp(int tx, int ty): x(tx), y(ty) {};

void Temp::print() {
	cout << "(" << this->x << " " << this->y << ")\n";
}

int main() {
	Temp* pt = new Temp(2, 3);
	pt->print();
	cout << "pt:addr:" << pt << "\n";

	Temp t(5, 6);
	cout << "t:addr:" << &t << "\n";
	
	vector<Temp> v;
	v.push_back(t);
	v[0].print();
	cout << "v0:addr:" << &v[0] << "\n";	// different from the one that was put in! (suggesting that a copy was pushed in!)
	v.back().print();
	cout << "vback:addr:" << &(v.back()) << "\n";	// returns the same object as v[0] (cool!)

	// vector<Temp&> vr;	// is not valid!!
	
	vector<Temp*> vp;
	vp.push_back(&t);
	vp[0]->print();
	cout << "vp0:addr:" << vp[0] << "\n";	// same as 't' address (cool!) - but need to make sure that these pointers remain valid.. if the object they reference to, is freed, they may point to garbage without knowing! - solution: smart pointers (see how?)

	vp.push_back(pt);
	// delete pt;	// if this statement is executed, the below statement return garbage! exactly why maintaining pointers to objects in stl containers is dangerous! (but if you just maintain the object, then it creates a copy of the object when storing in the container, which is not so good either)

	vp[1]->print();
	cout << "vp1:addr:" << vp[1] << "\n";
	return 0;
}