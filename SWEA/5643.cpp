#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int sz = 5e2;
int n, m;
vector<int> graph[sz];
vector<int> revgraph[sz];
bool visited[sz];
int answer;

void init() {
	for (int i = 0; i < sz; i++) {
		graph[i].clear();
		revgraph[i].clear();
	}
	answer = 0;
}

void input() {
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		--u; --v;
		graph[u].push_back(v);
		revgraph[v].push_back(u);
	}
}

int search(int start) {
	queue<int> q;
	q.push(start);
	fill(visited, visited + sz, false);
	visited[start] = true;
	int count = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (auto g : graph[front]) {
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			++count;
			q.push(g);
		}
	}
	return count;
}

int revsearch(int start) {
	queue<int> q;
	q.push(start);
	fill(visited, visited + sz, false);
	visited[start] = true;
	int count = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (auto g : revgraph[front]) {
			if (visited[g]) {
				continue;
			}
			visited[g] = true;
			++count;
			q.push(g);
		}
	}
	return count;
}

void solution() {
	for (int i = 0; i < n; i++) {
		cout << i << " " << search(i) << " + " << revsearch(i) << endl;
		int count = search(i) + revsearch(i);
		if (count == n - 1) {
			++answer;
		}
	}
}

void solve() {
	int t;
	cin >> t;
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
