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

const int sz = 101;
const int inf = 1e9;
int v, m, j, s;
vector<edge> graph[sz];
int jdist[sz], sdist[sz];

void input() {
	cin >> v >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> j >> s;
}

void jdijkstra() {
	fill(jdist, jdist + sz, inf);
	priority_queue<edge> pq;
	pq.push({ j,0 });
	jdist[j] = 0;
	while (!pq.empty()) {
		int vertex = pq.top().vertex;
		int weight = pq.top().weight;
		pq.pop();

		if (jdist[vertex] < weight) {
			continue;
		}

		for (auto g : graph[vertex]) {
			if (jdist[g.vertex] > weight + g.weight) {
				jdist[g.vertex] = weight + g.weight;
				pq.push({ g.vertex, jdist[g.vertex] });
			}
		}
	}
}

void sdijkstra() {
	fill(sdist, sdist + sz, inf);
	priority_queue<edge> pq;
	pq.push({ s,0 });
	sdist[s] = 0;
	while (!pq.empty()) {
		int vertex = pq.top().vertex;
		int weight = pq.top().weight;
		pq.pop();

		if (sdist[vertex] < weight) {
			continue;
		}

		for (auto g : graph[vertex]) {
			if (sdist[g.vertex] > weight + g.weight) {
				sdist[g.vertex] = weight + g.weight;
				pq.push({ g.vertex, sdist[g.vertex] });
			}
		}
	}
}

void process() {
	int fromj, answer, total, new_dist;
	answer = sz;
	total = inf;
	fromj = inf;
	vector<int> vec;

	for (int i = 1; i <= v; i++) {
		if (i == j || i == s) {
			continue;
		}
		if (jdist[i] >= inf || sdist[i] >= inf) {
			continue;
		}
		new_dist = jdist[i] + sdist[i];
		if (new_dist < total) {
			vec.clear();
			total = new_dist;
			vec.push_back(i);
		} else if (new_dist == total) {
			total = new_dist;
			vec.push_back(i);
		}
	}

	for (auto i : vec) {
		if (jdist[i] > sdist[i]) {
			continue;
		} else if (jdist[i] <= sdist[i]) {
			if (fromj > jdist[i]) {
				answer = i;
				fromj = jdist[i];
			} else if (fromj == jdist[i]) {
				answer = min(answer, i);
			}
		}
	}

	if (answer >= sz) {
		answer = -1;
	}
	cout << answer;
}

void solve() {
	input();
	jdijkstra();
	sdijkstra();
	process();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
