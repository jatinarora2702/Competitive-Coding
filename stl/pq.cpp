#include <bits/stdc++.h>
using namespace std;

class temp {
public:	
	int x, y;
	temp(int x_, int y_): x(x_), y(y_) {};
	void print() const {
		cout << "(" << this->x << ", " << this->y << ")\n";
	}
	const bool operator<(const temp& t) const {
		return this->x < t.x;
	}

	// const bool operator<(const temp& t) const {	// if using this one.. the insertion order is lost! (so, it all depends on pairwise comparisons and swaps done in the queue's implementation - the container does not give any quarantees.. - I guess so)
	// 	return this->x <= t.x;
	// }

	// const bool operator<(const temp& t) const {	// when using this one.. again.. the insertion order is lost for the items that kindof compare equal.. so, no container item order guarantees
	// 	return this->x > t.x;
	// }
};

priority_queue<temp> pq;

int main() {
	temp t1(5, 6);
	temp t2(5, 7);
	temp t3(3, 5);
	temp t4(5, 2);
	
	pq.push(t3);
	pq.push(t2);
	pq.push(t1);
	pq.push(t4);
	
	pq.top().print();
	pq.pop();
	
	pq.top().print();
	pq.pop();

	pq.top().print();
	pq.pop();

	pq.top().print();
	pq.pop();
	
	return 0;
}
