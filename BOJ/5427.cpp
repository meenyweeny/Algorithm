#include<iostream>
#include<deque>
#include<string>
using namespace std;

const char wall = '#';
const char fire = '*';
const string impossible = "IMPOSSIBLE";
const int sz = 1e3;
int n,m;
char map[sz][sz];
bool visited[sz][sz];
deque<pair<int, int>> fires;
pair<int, int> now;

void init() {
	fires.clear();
	fill(&visited[0][0], &visited[sz - 1][sz], false);
}

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == fire) {
				fires.push_back({ i,j });
				visited[i][j] = true;
			}
			else if (map[i][j] == '@') {
				now = { i,j };
			}
		}
	}
}

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void spread() {
	int length = fires.size();
	for (int k = 0; k < length; k++) {
		int fx = fires[k].first;
		int fy = fires[k].second;
		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';

			if (!check_range(nx, ny)) {
				continue;
			}
			if (map[nx][ny] == wall||map[nx][ny]==fire) {
				continue;
			}
			if (visited[nx][ny]) {
				continue;
			}
			map[nx][ny] = fire;
			visited[nx][ny] = true;
			fires.push_back({ nx,ny });
		}
	}
	while (length--) {
		fires.pop_front();
	}
}

int bfs() {
	deque<pair<pair<int, int>, int>> dq;
	dq.push_back({ {now.first, now.second }, 0 });
	int before = -1;
	visited[now.first][now.second] = true;
	while (!dq.empty()) {
		int fx = dq.front().first.first;
		int fy = dq.front().first.second;
		int count = dq.front().second;
		dq.pop_front();

		if (before != count) {
			spread();
			before = count;
		}
		++count;
		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';

			if (!check_range(nx, ny)) {
				return count;
			}
			if (map[nx][ny] == wall || map[nx][ny] == fire) {
				continue;
			}
			if (visited[nx][ny]) {
				continue;
			}
			visited[nx][ny] = true;
			dq.push_back({ {nx,ny}, count });
		}
	}
	return -1;
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		init();
		input();
		int result = bfs();
		cout << (result < 0 ? impossible : to_string(result)) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
