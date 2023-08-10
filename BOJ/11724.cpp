#include<iostream>
#include<deque>
using namespace std;

const int sz = 1e3 + 1;
int n, m;
deque<int> graph[sz];
bool visited[sz];

void bfs(int x) {
	deque<int> d;
	d.push_back(x);
	visited[x] = true;
	while (!d.empty()) {
		int front = d.front();
		d.pop_front();
		for (auto g : graph[front]) {
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			d.push_back(g);
		}
	}
}

void solve() {
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			++answer;
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
