#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int sz = 1e4 + 1;
int n;
deque<int> graph[sz];
bool visited[sz];

int bfs(int x) {
	fill(visited, visited + sz, false);
	int ret = 0;
	deque<pair<int,int>> q;
	q.push_back({ x,0 });
	visited[x] = true;

	while (!q.empty()) {
		int front = q.front().first;
		int count = q.front().second+1;
		++ret;
		q.pop_front();

		for (auto g : graph[front]) {
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			q.push_back({ g, count});
		}
	}
	return ret;
}

void solve() {
	int m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[b].push_back(a);
	}
	deque<int> path;
	int maximum = -1;
	for (int i = 1; i <= n; i++) {
		int k = bfs(i);
		if (maximum == k) {
			path.push_back(i);
		} else if (maximum < k) {
			path.clear();
			path.push_back(i);
			maximum = k;
		}
	}
	for (auto p : path) {
		cout << p << ' '; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
