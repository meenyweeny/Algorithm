#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge {
	int u, v, d;

	bool operator<(const edge & b) const {
		return d < b.d;
	}
};

const int sz = 1e5 + 1;
int v, e;
int par[sz];
vector<edge> edges;

void input() {
	cin >> v >> e;
	int a, b, c;
	while (e--) {
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}
}

void init() {
	for (int i = 0; i <= v; i++) {
		par[i] = i;
	}
}

int find(int x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

bool merge(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);

	if (xroot == yroot) {
		return false;
	}
	if (xroot > yroot) {
		swap(xroot, yroot);
	}
	par[xroot] = yroot;
	return true;
}

void solution() {
	int goal = v - 1;
	int cost = 0;
	sort(edges.begin(), edges.end());
	for (auto e : edges) {
		if (merge(e.u, e.v)) {
			cost += e.d;
			--goal;
		}
		if (!goal) {
			break;
		}
	}
	cout << cost;
}

void solve() {
	input();
	init();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
