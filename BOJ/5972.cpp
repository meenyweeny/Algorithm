#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct edge {
	int vertex, weight;

	bool operator<(const edge & b) const {
		return weight > b.weight;
	}
};

const int sz = 5e5 + 1;
const int inf = 1e9;
int n, m;
vector<edge> graph[sz];
int dist[sz];

void input() {
	int a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
}

void dijkstra() {
	fill(dist, dist + sz, inf);
	dist[1] = 0;
	priority_queue<edge> pq;
	pq.push({ 1,0 });
	while (!pq.empty()) {
		int vertex = pq.top().vertex;
		int weight = pq.top().weight;
		pq.pop();

		if (dist[vertex] < weight) {
			continue;
		}

		for (auto g : graph[vertex]) {
			if (dist[g.vertex] > weight + g.weight) {
				dist[g.vertex] = weight + g.weight;
				pq.push({ g.vertex,dist[g.vertex] });
			}
		}
	}

	cout << dist[n];
}

void solve() {
	input();
	dijkstra();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
