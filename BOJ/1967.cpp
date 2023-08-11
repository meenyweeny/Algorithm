#include<iostream>
#include<vector>
using namespace std;

const int sz = 1e4 + 1;
int n, node, dist = -1;
vector<pair<int, int>> graph[sz];
bool visited[sz];

void dfs(int x, int d) {
	visited[x] = true;
	if (d > dist) {
		node = x;
		dist = d;
	}
	for (auto g : graph[x]) {
		if (visited[g.first]) {
			continue;
		}
		dfs(g.first, d + g.second);
	}
}

void solve() {
	cin >> n;
	int u, v, d;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> d;
		graph[u].push_back({ v,d });
		graph[v].push_back({ u,d });
	}
	dfs(1, 0);
	fill(visited, visited + sz, false);
	dfs(node, 0);
	cout << dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
