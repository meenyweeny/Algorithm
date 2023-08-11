#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int bug = 2;
const int wall = 1;
int n, m, answer = -1;
int map[8][8];
deque<pair<int, int>> virus;
deque<pair<int, int>> safearea;
bool visited[8][8];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = (map[i][j] != 0);
		}
	}
}

int getSafeareaSize() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += (!visited[i][j]);
		}
	}
	return ret;
}

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs() {
	deque<pair<int, int>> q = virus;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop_front();
		visited[fx][fy] = true;
		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';

			if (!check_range(nx, ny)) {
				continue;
			}
			if (visited[nx][ny]) {
				continue;
			}
			if (map[nx][ny] != 0) {
				continue;
			}
			visited[nx][ny] = true;
			q.push_back({ nx,ny });
		}
	}
}

void run(int count,int x) {
	if (count == 3) {
		init();
		bfs();
		answer = max(answer, getSafeareaSize());
		return;
	}

	for (int i = x; i < safearea.size(); i++) {
		pair<int, int> now = safearea[i];
		if (map[now.first][now.second] != 0) {
			continue;
		}
		map[now.first][now.second] = wall;
		run(count + 1, i + 1);
		map[now.first][now.second] = 0;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == bug) {
				virus.push_back({i,j});
			}
			else if (!map[i][j]) {
				safearea.push_back({ i,j });
			}
		}
	}
	run(0, 0);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
