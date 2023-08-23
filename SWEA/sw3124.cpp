#include<iostream>
#include<queue>
using namespace std;

struct edge {
	int u, v, weight;

	bool operator<(const edge & b) const {
		return weight > b.weight;
	}
};

const int sz = 1e5 + 1;
int v, e;
long long weight;
int par[sz];
priority_queue<edge> edges;

void init() {
	for (int i = 0; i < sz; i++) {
		par[i] = i;
	}
	while (!edges.empty()) {
		edges.pop();
	}
}

void input() {
	int a, b, c;
	cin >> v >> e;
	while (e--) {
		cin >> a >> b >> c;
		edges.push({ a,b,c });
	}
}

int find(int x) {
	if (par[x] == x) {
		return x;
	} else {
		par[x] = find(par[x]);
	}
}

bool merge(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);

	if (xroot != yroot) {
		par[xroot] = yroot;
		return false;
	}
	return true;
}

void solution() {
	weight = 0;
	int goal = v - 1;
	while (1) {
		edge top = edges.top();
		edges.pop();

		if (!merge(top.u, top.v)) {
			weight += top.weight;
			--goal;
		}

		if (goal == 0) {
			break;
		}
	}
}

void solve() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		solution();
		cout << '#' << tc << ' ' << weight << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
