#include <bits/stdc++.h>
using namespace std;

class temp {
public:
	int x, y;
	temp(int tx, int ty): x(tx), y(ty) {};
	void print() const {
		cout << "(" << this->x << ", " << this->y << ")\n";
	}
	const bool operator<(const temp& t) const {
		return this->x > t.x;
	}
};

bool fn(const temp& t1, const temp& t2) {
	return t1.y < t2.y;
}

int main() {
	vector<temp> v;

	temp t1(5, 6);
	v.push_back(t1);

	temp t2(7, 8);
	v.push_back(t2);

	// sort(v.begin(), v.end(), [](const temp& p1, const temp& p2)->bool {
	// 	return p1.x > p2.x;
	// });

	sort(v.begin(), v.end(), fn);

	for(int i = 0; i < v.size(); i++) {
		v[i].print();
	}

	cout << "done\n";

	for(auto& it: v) {
		it.print();
	}

	cout << "another done\n";

	set<int> st;
	st.insert(5);
	st.insert(6);
	st.insert(1);
	st.insert(2);

	for(auto& it: st) {
		cout << it << " ";
	}
	cout << "\n";

	cout << "working with int sets in reverse using auto\n";
	for(auto it = st.rbegin(); it != st.rend(); it++) {
		cout << *it << " ";
	}
	cout << "\n";

	set<temp> stt;
	stt.insert(t1);
	stt.insert(t2);

	for(auto& it: stt) {
		it.print();	// requires the print function to be declared const (no modification guarantee)
	}

	cout << "working with sets auto in reverse\n";
	for(auto it = stt.rbegin(); it != stt.rend(); it++) {
		it->print();
	}

	cout << "now, working with maps:\n";

	map<temp, int> mp;
	mp[t1] = 1;
	mp[t2] = 4;

	for(auto& it: mp) {
		it.first.print();
		cout << it.second << "\n";
	}

	cout << "maps with auto in reverse:\n";
	for(auto it = mp.rbegin(); it != mp.rend(); it++) {
		it->first.print();
		cout << it->second << "\n";
	}

	return 0;
}
