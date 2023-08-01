#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int sz = 1e5 + 1;
int n, m, r;
vector<int> graph[sz];
int turn[sz];
int cnt = 1;

void dfs(int k) {
	turn[k] = cnt++;
	for (auto x : graph[k]) {
		if (turn[x]) {
			continue;
		}
		dfs(x);
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
		reverse(graph[i].begin(), graph[i].end());
	}
	dfs(r);
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
