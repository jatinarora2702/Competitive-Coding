#include <bits/stdc++.h>
using namespace std;

class temp {
	int x, y;
public:
	temp(int, int);
	temp(const temp&);
	static void fn(temp);
	void print() const;
};

temp::temp(int tx, int ty): x(tx), y(ty) {};
temp::temp(const temp& t): x(t.x), y(t.y) {
	cout << "done\n";
}
void temp::fn(temp t) {
	t.x++;
	t.y++;
	t.print();
}
void temp::print() const {
	cout << "(" << this->x << ", " << this->y << ")\n";
}

int main() {
	temp t(4, 5);
	t.print();

	temp tc(t);
	tc.print();

	temp::fn(t);

	return 0;
}