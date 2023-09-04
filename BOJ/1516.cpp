#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int sz = 5e2 + 1;
int n;
vector<int> graph[sz];
int cost[sz];
int indegree[sz];
int weight[sz];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		int prev = 0;
		while (1) {
			cin >> prev;
			if (prev == -1) {
				break;
			}
			++indegree[i];
			graph[prev].push_back(i);
		}
	}
}

void solution() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
			weight[i] = cost[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			break;
		}

		int front = q.front();
		q.pop();

		for (auto g : graph[front]) {
			--indegree[g];
			if (!indegree[g]) {
				q.push(g);
			}
			weight[g] = max(weight[front] + cost[g], weight[g]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << weight[i] << '\n';
	}
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
