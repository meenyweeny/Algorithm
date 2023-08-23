#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge {
	int vertex, weight;

	bool operator<(const edge & b) const {
		return weight > b.weight;
	}
};

const int sz = 1e4 + 1;
const int inf = 1e9;
int n, d, c;
int dist[sz];
vector<edge> graph[sz];

void init() {
	for (int i = 0; i < sz; i++) {
		graph[i].clear();
	}
}

void input() {
	int a, b, s;
	cin >> n >> d >> c;
	while (d--) {
		cin >> a >> b >> s;
		graph[b].push_back({ a,s });
	}
}

void dijkstra() {
	fill(dist, dist + sz, inf);
	priority_queue<edge> pq;
	pq.push({ c,0 });
	dist[c] = 0;

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
				pq.push({ g.vertex, dist[g.vertex] });
			}
		}
	}
}

void solution() {
	dijkstra();
	int time = -1;
	int computer = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] >= inf) {
			continue;
		}
		++computer;
		time = max(time, dist[i]);
	}
	cout << computer << ' ' << time << '\n';
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		init();
		input();
		solution();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
