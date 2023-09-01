#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge {
	int start, end, weight;

	bool operator<(const edge & b) const {
		return weight < b.weight;
	}
};

const int sz = 2e5;
int n, m, cost;
int par[sz];
vector<edge> edges;

void init() {
	for (int i = 0; i < sz; i++) {
		par[i] = i;
	}
	cost = 0;
	edges.clear();
}

void input() {
	int x, y, z;
	for(int i=0; i<m; i++) {
		cin >> x >> y >> z;
		cost += z;
		edges.push_back({ x,y,z });
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
	}
	if (xroot < yroot) {
		swap(xroot, yroot);
	}
	par[xroot] = yroot;
	return true;
}

void solution() {
	sort(edges.begin(), edges.end());
	int total = n - 1;
	int weight = 0;
	for (auto e : edges) {
		if (merge(e.start, e.end)) {
			weight += e.weight;
			--total;
		}
		if (!total) {
			break;
		}
	}
	cout << cost - weight << '\n';
}

void solve() {
	cin >> n >> m;
	while (n != 0) {
		init();
		input();
		solution();
		cin >> n >> m;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
