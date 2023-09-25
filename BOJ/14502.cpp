#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, answer;
int map[8][8];
int dup[8][8];
queue<pair<int, int>> virus;
vector<pair<int, int>> room;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push({ i,j });
			} else if (map[i][j] == 0) {
				room.push_back({ i,j });
			}
		}
	}
}

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dup[i][j] = map[i][j];
		}
	}
}

bool check_range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int get_safe_area() {
	queue<pair<int, int>> q = virus;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';

			if (!check_range(nx, ny)) {
				continue;
			}

			if (dup[nx][ny] > 0) {
				continue;
			}

			dup[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}
	int safe_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			safe_area += (dup[i][j] == 0);
		}
	}
	return safe_area;
}

void process(int count, int start, int wall[3]) {
	if (count == 3) {
		copy();
		for (int i = 0; i < 3; i++) {
			dup[room[wall[i]].first][room[wall[i]].second] = 1;
		}
		answer = max(answer, get_safe_area());
		return;
	}
	for (int i = start; i < room.size(); i++) {
		wall[count] = i;
		process(count + 1, i + 1, wall);
	}
}

void solution() {
	int list[3];
	process(0, 0, list);
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
