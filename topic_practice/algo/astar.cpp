#include <bits/stdc++.h>
using namespace std;

class State {
public:
	int si, sj, pi, pj;
	double f, g, h;
	State(int _si, int _sj, double _f, double _g, double _h) {
		this->si = _si;
		this->sj = _sj;
		this->f = _f;
		this->g = _g;
		this->h = _h;
	}
	// const bool operator<(const State& s) const {
	// 	return this->f < s.f;
	// }
	const bool operator>(const State& s) const {
		return this->f > s.f;
	}
};

double get_h(int si, int sj, int gi, int gj) {
	return sqrt((gi-si)*(gi-si) + (gj-sj)*(gj-sj));
}

void update(vector<vector<int>>& grid, vector<vector<double>>& cost, priority_queue<State, vector<State>, greater<State>>& pq, double g, int si, int sj, int gi, int gj) {
	int n = grid.size();
	int m = grid[0].size();
	if (si < 0 || si >= n || sj < 0 || sj >= m || grid[si][sj] == 0) {
		return;
	}
	double h = get_h(si, sj, gi, gj);
	double f = g + h;
	if (cost[si][sj] >= f) {
		pq.push(State(si, sj, f, g, h));
	}
}

int main() {
	vector<vector<int>> grid { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
    };
    int n, m;
    n = grid.size();
    m = grid[0].size();
	int si, sj, gi, gj;
	si = 8;
	sj = 0;
	gi = 0;
	gj = 0;
	priority_queue<State, vector<State>, greater<State>> pq;
	double inf = m * n + 1.0;
	vector<vector<double>> cost(n, vector<double>(m, inf));
	double h = get_h(si, sj, gi, gj);
	pq.push(State(si, sj, h, 0.0, h));
	while(pq.size() > 0) {
		State s = pq.top();
		pq.pop();
		if (cost[s.si][s.sj] < s.f) {
			continue;
		}
		cost[s.si][s.sj] = s.f;
		if (s.si == gi && s.sj == gj) {
			break;
		}
		double g = s.g + 1.0;
		update(grid, cost, pq, g, s.si-1, s.sj-1, gi, gj);
		update(grid, cost, pq, g, s.si-1, s.sj, gi, gj);
		update(grid, cost, pq, g, s.si-1, s.sj+1, gi, gj);
		update(grid, cost, pq, g, s.si, s.sj-1, gi, gj);
		update(grid, cost, pq, g, s.si, s.sj+1, gi, gj);
		update(grid, cost, pq, g, s.si+1, s.sj-1, gi, gj);
		update(grid, cost, pq, g, s.si+1, s.sj, gi, gj);
		update(grid, cost, pq, g, s.si+1, s.sj+1, gi, gj);
	}
	cout << cost[gi][gj] << "\n";
	return 0;
}