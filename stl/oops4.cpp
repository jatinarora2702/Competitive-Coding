#include <bits/stdc++.h>
using namespace std;

class temp1 {
protected:
	int x;
	temp1(int);
public:
	virtual void fn() = 0;
};

class temp2: public temp1 {
	int y;
public:
	temp2(int, int);
	void fn();
};

temp1::temp1(int tx): x(tx) {};
temp2::temp2(int tx, int ty): temp1(tx), y(ty) {};
void temp2::fn() {
	cout << "(" << this->x << ", " << this->y << ")\n";
}

int main() {
	temp2 t(4, 5);
	t.fn();
	return 0;
}
