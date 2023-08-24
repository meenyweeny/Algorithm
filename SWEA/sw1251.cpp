#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

struct edge {
	int start, end;
	unsigned long long weight;

	bool operator<(const edge & b) const {
		return weight > b.weight;
	}
};

const int sz = 1e3 + 1;
unsigned long long answer = 0;
int n;
double e;
pair<int, int> location[sz];
priority_queue<edge> edges;
int par[sz];

void init() {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	answer = 0;
	while (!edges.empty()) {
		edges.pop();
	}
}

unsigned long long get_distance(pair<int, int> a, pair<int, int> b) {
	long long x = (a.first - b.first) * (a.first - b.first);
	long long y = (a.second - b.second) * (a.second - b.second);
	return pow((a.first - b.first),2) + pow((a.second - b.second), 2);
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> location[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> location[i].second;
	}
	cin >> e;
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
	if (xroot == yroot) {
		return false;
	} else {
		par[xroot] = yroot;
		return true;
	}
}

void kruskal() {
	int loop = n-1;
	while (loop) {
		edge top = edges.top();
		edges.pop();
		if (merge(top.start, top.end)) {
			answer += top.weight;
			--loop;
		}
	}
}

void set_distance() {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			edges.push({ i,j, get_distance(location[i], location[j]) });
		}
	}
}

void solution() {
	set_distance();
	kruskal();
	long double tmp = answer;
	tmp *= e;
	tmp = floor(tmp + 0.5);
	answer = tmp;
}

void solve() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		input();
		init();
		solution();
		cout << '#' << tc << ' ' << answer << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
