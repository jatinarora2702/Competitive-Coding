#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef complex < double > point;

int main() {
	point p1, p2;
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p1 + p2 << endl;
	cout << conj(p1) << endl;
	cout << 1.5 * p1 << endl;
	cout << norm(p1 - p2) << endl;
	cout << arg(p1 - p2) << endl;
	cout << point(abs(p1), arg(p1)) << endl;
	cout << conj(p1) * p2 << endl;	// dot, cross
	return 0;
}