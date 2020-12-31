#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair < int, int > pii;
typedef pair < pii, pii > rect;

vector < rect > intersect(rect r1, rect r2) {
	vector < rect > v;
	int x1 = max(r1.FF.FF, r2.FF.FF);
	int y1 = max(r1.FF.SS, r2.FF.SS);
	int x2 = min(r1.SS.FF, r2.SS.FF);
	int y2 = min(r1.SS.SS, r2.SS.SS);

	if (!(x1 < x2 && y1 < y2)) {
		v.PB(r1);
		return v;
	}

	rect rr1 = MP(MP(r1.FF.FF, r1.FF.SS), MP(x2, y1));
	rect rr2 = MP(MP(x2, r1.FF.SS), MP(r1.SS.FF, y2));
	rect rr3 = MP(MP(x1, y2), MP(r1.SS.FF, r1.SS.SS));
	rect rr4 = MP(MP(r1.FF.FF, y1), MP(x1, r1.SS.SS));
	if (rr1.FF.FF < rr1.SS.FF && rr1.FF.SS < rr1.SS.SS) {
		v.PB(rr1);
	}
	if (rr2.FF.FF < rr2.SS.FF && rr2.FF.SS < rr2.SS.SS) {
		v.PB(rr2);
	}
	if (rr3.FF.FF < rr3.SS.FF && rr3.FF.SS < rr3.SS.SS) {
		v.PB(rr3);
	}
	if (rr4.FF.FF < rr4.SS.FF && rr4.FF.SS < rr4.SS.SS) {
		v.PB(rr4);
	}
	return v;
}

int main() {
	rect r1, r2, r3;
	vector < rect > v;
	cin >> r1.FF.FF >> r1.FF.SS >> r1.SS.FF >> r1.SS.SS;
	cin >> r2.FF.FF >> r2.FF.SS >> r2.SS.FF >> r2.SS.SS;
	cin >> r3.FF.FF >> r3.FF.SS >> r3.SS.FF >> r3.SS.SS;
	v = intersect(r1, r2);
	for(int i = 0; i < v.size(); i++) {
		if (intersect(v[i], r3).size() > 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}