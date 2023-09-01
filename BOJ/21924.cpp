#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
	int start, end, weight;

	bool operator<(const edge & b) const {
		return weight < b.weight;
	}
};

const int sz = 1e5 + 1;
int n, m;
unsigned long long weight;
int par[sz];
vector<edge> edges;

void input() {
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		weight += c;
		edges.push_back({ a,b,c });
	}
}

void init() {
	for (int i = 0; i <= n; i++) {
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
	if (xroot < yroot) {
		swap(xroot, yroot);
	}
	par[xroot] = yroot;
	return true;
}

void solution() {
	sort(edges.begin(), edges.end());

	int total = n - 1;
	unsigned long long cost = 0;
	for (auto e : edges) {
		if (merge(e.start, e.end)) {
			cost += e.weight;
			--total;
		}
		if (!total) {
			break;
		}
	}
	long long answer = weight - cost;
	int origin = find(par[1]);
	for (int i = 2; i <= n; i++) {
		if (origin != find(par[i])) {
			answer = -1;
			break;
		}
	}
	cout << answer;
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
