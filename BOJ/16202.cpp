#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct edge {
	int src, dest, weight;

	bool operator<(const edge & b) const {
		return weight < b.weight;
	}
};

const int sz = 1e3 + 1;
int n, m, k;
deque<edge> edges;
int score[100];
int par[sz];

void input() {
	cin >> n >> m >> k;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		edges.push_back({ x,y,i });
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
	}
	else {
		return par[x] = find(par[x]);
	}
}

bool merge(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);
	if (xroot == yroot) {
		return false;
	}
	else {
		if (xroot > yroot) {
			swap(xroot, yroot);
		}
		par[yroot] = xroot;
		return true;
	}
}

void solution() {
	sort(edges.begin(), edges.end());
	for (int i = 0; i < k; i++) {
		init();
		if (edges.empty()) {
			break;
		}
		int sum = 0;
		int total = n - 1;
		for (auto e : edges) {
			if (merge(e.src, e.dest)) {
				sum += e.weight;
				--total;
			}
			if (!total) {
				break;
			}
		}
		if (!total) {
			score[i] = sum;
		}
		if (total) {
			break;
		}
		edges.pop_front();
	}
	for (int i = 0; i < k; i++) {
		cout << score[i] << ' ';
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
