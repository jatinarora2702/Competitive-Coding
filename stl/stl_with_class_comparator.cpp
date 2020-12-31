#include <bits/stdc++.h>
using namespace std;

class Temp {
	int x, y;
public:
	Temp(int, int);
	const bool operator<(const Temp&) const;
	void print();
};

Temp::Temp(int tx, int ty): x(tx), y(ty) {};

const bool Temp::operator<(const Temp& t) const {
	return this->x < t.x;
}

void Temp::print() {
	cout << "(" << this->x << ", " << this->y << ")\n";
}

int main() {
	vector<Temp> v;
	Temp t1(4, 5);
	Temp t2(3, 4);
	v.push_back(t1);
	v.push_back(t2);
	sort(v.begin(), v.end());
	v[0].print();
	v[1].print();
}