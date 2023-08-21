#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct edge {
	int vertex;
	int weight;

	bool operator<(const edge & b) const {
		return weight > b.weight;
	}
};

const int sz = 1e3 + 1;
int n, m, x;
vector<edge> graph[sz];
vector<edge> revgraph[sz];
int dist[sz];
int revdist[sz];

void init() {
	fill(dist, dist + sz, 2e9);
	fill(revdist, revdist + sz, 2e9);
}

void input() {
	cin >> n >> m >> x;
	int u, v, t;
	while (m--) {
		cin >> u >> v >> t;
		graph[u].push_back({ v,t });
		revgraph[v].push_back({ u,t });
	}
}

void dijkstra() {
	priority_queue<edge> pq;
	pq.push({ x,0 });
	dist[x] = 0;
	while (!pq.empty()) {
		int front = pq.top().vertex;
		int weight = pq.top().weight;
		pq.pop();

		if (dist[front] < weight) {
			continue;
		}

		for (auto e : graph[front]) {
			if (dist[e.vertex] > weight + e.weight) {
				dist[e.vertex] = weight + e.weight;
				pq.push({ e.vertex,dist[e.vertex] });
			}
		}
	}
}

void revdijkstra() {
	priority_queue<edge> pq;
	pq.push({ x,0 });
	revdist[x] = 0;
	while (!pq.empty()) {
		int front = pq.top().vertex;
		int weight = pq.top().weight;
		pq.pop();

		if (revdist[front] < weight) {
			continue;
		}

		for (auto e : revgraph[front]) {
			if (revdist[e.vertex] > weight + e.weight) {
				revdist[e.vertex] = weight + e.weight;
				pq.push({ e.vertex,revdist[e.vertex] });
			}
		}
	}
}

void solve() {
	input();
	init();
	dijkstra();
	revdijkstra();
	int maxdist;
	maxdist = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		if (dist[i] + revdist[i] > maxdist) {
			maxdist = dist[i] + revdist[i];
		}
	}
	cout << maxdist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
