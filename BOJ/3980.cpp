#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, answer = -1;
bool visited[11];
vector<pair<int, int>> power[11];

void input() {
	int a;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> a;
			if (!a) {
				continue;
			}
			power[i].push_back({ j,a });
		}
	}
}

void init() {
	fill(visited, visited + 11, false);
	for (int i = 0; i < 11; i++) {
		power[i].clear();
	}
	answer = -1;
}

void process(int sum,int next) {
	if (next == 11) {
		answer = max(answer, sum);
		return;
	}
	bool flag = false;
	for (auto p : power[next]) {
		if (visited[p.first]) {
			continue;
		}
		flag = true;
		visited[p.first] = true;
		process(sum + p.second, next + 1);
		visited[p.first] = false;
	}
	if (!flag) {
		return;
	}
}

void solution() {
	input();
	process(0, 0);
	cout << answer << '\n';
}

void solve() {
	int c;
	cin >> c;
	while (c--) {
		init();
		solution();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
