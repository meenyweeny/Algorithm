#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct edge {
	int u, v, d;

	bool operator<(const edge & b) const {
		return d < b.d;
	}
};

const int sz = 1e3 + 1;
int n, m;
int par[sz];
deque<edge> edges;

void input() {
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
}

int find(int x) {
	if (x == par[x]) {
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
	} else {
		if (xroot < yroot) {
			par[yroot] = xroot;
		} else {
			par[xroot] = yroot;
		}
		return true;
	}
}

void solution() {
	sort(edges.begin(), edges.end());
	int total = n - 1;
	int weight = 0;
	while (total > 0 && !edges.empty()) {
		edge e = edges.front();
		edges.pop_front();
		if (merge(e.u, e.v)) {
			weight += e.d;
		}
	}
	cout << weight;
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
