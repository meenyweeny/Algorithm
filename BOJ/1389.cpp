#include<iostream>
#include<deque>
using namespace std;

const int sz = 1e2 + 1;
int n;
deque<int> graph[sz];
bool visited[sz];

int bfs(int x) {
	fill(visited, visited + sz, false);
	int kevin = 0;
	deque<pair<int, int>> q;
	q.push_back({ x,0 });
	visited[x] = true;
	while (!q.empty()) {
		int front = q.front().first;
		int count = q.front().second;
		kevin += count;
		++count;
		q.pop_front();

		for (auto g : graph[front]) {
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			q.push_back({ g,count });
		}
	}
	return kevin;
}

void solve() {
	int m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int minimum, answer, kevin;
	minimum = 2e9;
	for (int i = n; i > 0 ; i--) {
		kevin = bfs(i);
		if (minimum >= kevin) {
			minimum = kevin;
			answer = i;
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
