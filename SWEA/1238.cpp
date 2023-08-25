#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int inf = 1e9;
const int sz = 101;
int n,m,answer;
int dist[sz];
vector<int> graph[sz];

void init() {
	fill(dist, dist + sz, inf);
	for (int i = 0; i < sz; i++) {
		graph[i].clear();
	}
	answer = 0;
}

void input() {
	cin >> m >> n;
	m /= 2;
	int a, b;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
}

void dijkstra() {
	dist[n] = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(n);
	while (!pq.empty()) {
		int front = pq.top();
		pq.pop();

		for (auto g : graph[front]) {
			if (dist[g] > dist[front] + 1) {
				dist[g] = dist[front] + 1;
				pq.push(g);
			}
		}
	}
}

void get_answer() {
	int maxnum = 0;
	for (int i = 1; i < sz; i++) {
		if (dist[i] >= inf) {
			continue;
		}
		if (dist[i] >= maxnum) {
			answer = i;
			maxnum = dist[i];
		}
	}
}

void solution() {
	dijkstra();
	get_answer();
}

void solve() {
	int t;
	t = 10;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
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
