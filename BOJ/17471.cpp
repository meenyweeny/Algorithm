#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int inf = 2e9;
int n, answer = inf;
int people[10];
vector<int> graph[10];
bool visited[10];
bool connected[10];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}
	int a, k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (a--) {
			cin >> k;
			--k;
			graph[i].push_back(k);
			graph[k].push_back(i);
		}
	}
}

int bfs(bool flag) {
	fill(visited, visited + 10, false);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (connected[i] == flag) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (auto g : graph[front]) {
			if (connected[g] != flag) {
				continue;
			}
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			q.push(g);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (connected[i] != flag) {
			continue;
		}
		if (flag) {
			if (connected[i]==visited[i]) {
				ret += people[i];
			} else {
				ret = -1;
				break;
			}
		} else {
			if (!connected[i] && visited[i]) {
				ret += people[i];
			} else {
				ret = -1;
				break;
			}
		}
	}
	return ret;
}

void solution() {
	int endpoint = (1 << n) - 1;
	for (int i = 1; i < endpoint; i++) {
		for (int j = 0; j < n; j++) {
			int pos = (1 << j);
			connected[j] = (i & pos) == 0;
		}
		int a = bfs(true);
		int b = bfs(false);
		if (a >= 0 && b >= 0) {
			answer = min(answer, abs(a-b));
		}
	}
	if (answer >= inf) {
		answer = -1;
	}
	cout << answer;
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
