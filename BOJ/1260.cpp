#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int sz = 1e3 + 1;
int n, m, v;
deque<int> graph[sz];
bool visited[sz];

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	for (auto g : graph[x]) {
		if (visited[g]) {
			continue;
		}
		dfs(g);
	}
}

void bfs() {
	deque<int> d;
	d.push_back(v);
	visited[v] = true;
	while (!d.empty()) {
		int front = d.front();
		cout << front << " ";
		d.pop_front();

		for (auto g : graph[front]) {
			if (visited[g]) {
				continue;
			}
			d.push_back(g);
			visited[g] = true;
		}
	}
}

void solve() {
	cin >> n >> m >> v;
	int a, b;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	fill(visited, visited + n + 1, false);
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
