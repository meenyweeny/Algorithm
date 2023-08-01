#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int sz = 1e5 + 1;
int n, m, r;
deque<int> graph[sz];
int turn[sz];
int cnt = 1;

void bfs() {
	deque<int> dq;
	dq.push_back(r);
	turn[r] = cnt;
	while (!dq.empty()) {
		int front = dq.front();
		dq.pop_front();
		for (auto g : graph[front]) {
			if (turn[g]) {
				continue;
			}
			turn[g] = ++cnt;
			dq.push_back(g);
		}
	}
}

void solve() {
	cin >> n >> m >> r;
	int u, v;
	while (m--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		cout << turn[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
