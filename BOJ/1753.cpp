#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct edge {
	int vertex;
	int weight;

	bool operator<(const edge& b) const {
		return this->weight > b.weight;
	}
};

const int sz = 2e4 + 1;
const int inf = 1e9;
int v, e, k;
int dist[sz];
vector<edge> graph[sz];

void init() {
	fill(dist, dist + sz, inf);
}

void input() {
	cin >> v >> e;
	cin >> k;
	int a, b, w;
	while (e--) {
		cin >> a >> b >> w;
		graph[a].push_back({ b,w });
	}
}

void dijkstra() {
	priority_queue<edge> pq;
	pq.push({ k,0 });
	dist[k] = 0;

	while (!pq.empty()) {
		edge top = pq.top();
		pq.pop();

		int vertex = top.vertex;
		int weight = top.weight;

		if (dist[vertex] < weight) {
			continue;
		}

		for (auto next : graph[vertex]) {
			if (dist[next.vertex] > weight + next.weight) {
				dist[next.vertex] = weight + next.weight;
				pq.push({ next.vertex,dist[next.vertex] });
			}
		}
	}
}

void print() {
	for (int i = 1; i <= v; i++) {
		cout << (dist[i] >= inf ? "INF" : to_string(dist[i])) << '\n';
	}
}

void solve() {
	init();
	input();
	dijkstra();
	print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
