#include<iostream>
#include<vector>
#include<tuple>
#include <numeric>
#include<set>

using namespace std;

inline bool is_connected(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first == b.first || a.second == b.second;
}

inline int find_par(const vector<int> &pars, int idx) {
	while (idx != pars[idx]) idx = pars[idx];
	return idx;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (auto &e : v) {
		cin >> e.first >> e.second;
	}

	vector<int> pars(n);
	iota(pars.begin(), pars.end(), 0);
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			if (is_connected(v[i], v[j])) {
				int p = find_par(pars, j);
				int ir = find_par(pars, i);
				if (ir == p) continue;
				pars[p] = ir;
			}
		}
	}

	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(find_par(pars, i));
	}

	cout << s.size() - 1;
}
