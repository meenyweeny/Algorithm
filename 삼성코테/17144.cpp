#include<iostream>
#include<deque>
using namespace std;

int r, c, t;
int map[50][50];
int dust[50][50];
pair<int, int> up, down;

void input() {
	cin >> r >> c >> t;
	int index = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				index == 0 ? up = { i,j } : down = { i,j };
				++index;
			}
		}
	}
}

int get_sum() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] < 0) {
				continue;
			}
			sum += map[i][j];
		}
	}
	return sum;
}

bool check_range(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

void spread() {
	fill(&dust[0][0], &dust[49][50], 0);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] <= 0) {
				continue;
			}

			int total = map[i][j];

			int count = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + "2011"[k] - '1';
				int ny = j + "1120"[k] - '1';

				if (!check_range(nx, ny)) {
					continue;
				}
				if (map[nx][ny] == -1) {
					continue;
				}
				dust[nx][ny] += (total / 5);
				++count;
			}
			dust[i][j] += (total - ((total / 5) * count));
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == -1) {
				continue;
			}
			map[i][j] = dust[i][j];
		}
	}
}

void rotate_up() {
	deque<int> dq;
	map[up.first][up.second] = 0;
	for (int i = 0; i <= up.first; i++) {
		dq.push_back(map[i][0]);
	}
	for (int i = 1; i < c; i++) {
		dq.push_back(map[up.first][i]);
	}
	for (int i = up.first - 1; i > 0; i--) {
		dq.push_back(map[i][c - 1]);
	}
	for (int i = c - 1; i > 0; i--) {
		dq.push_back(map[0][i]);
	}
	dq.push_front(dq.back());
	dq.pop_back();
	for (int i = 0; i <= up.first; i++) {
		map[i][0] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i < c; i++) {
		map[up.first][i] = dq.front();
		dq.pop_front();
	}
	for (int i = up.first - 1; i > 0; i--) {
		map[i][c-1] = dq.front();
		dq.pop_front();
	}
	for (int i = c - 1; i > 0; i--) {
		map[0][i] = dq.front();
		dq.pop_front();
	}
	map[up.first][up.second] = -1;
}

void rotate_down() {
	deque<int> dq;
	map[down.first][down.second] = 0;
	for (int i = 0; i < c; i++) {
		dq.push_back(map[down.first][i]);
	}
	for (int i = down.first + 1; i < r; i++) {
		dq.push_back(map[i][c - 1]);
	}
	for (int i = c - 2; i >= 0; i--) {
		dq.push_back(map[r - 1][i]);
	}
	for (int i = r - 2; i > down.first; i--) {
		dq.push_back(map[i][0]);
	}
	dq.push_front(dq.back());
	dq.pop_back();
	for (int i = 0; i < c; i++) {
		map[down.first][i] = dq.front();
		dq.pop_front();
	}
	for (int i = down.first + 1; i < r; i++) {
		map[i][c - 1] = dq.front();
		dq.pop_front();
	}
	for (int i = c - 2; i >= 0; i--) {
		map[r - 1][i] = dq.front();
		dq.pop_front();
	}
	for (int i = r - 2; i > down.first; i--) {
		map[i][0] = dq.front();
		dq.pop_front();
	}
	map[down.first][down.second] = -1;
}

void airclear() {
	rotate_up();
	rotate_down();
}

void solution() {
	for(int i=0; i<t; i++) {
		spread();
		airclear();
	}
	cout << get_sum();
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
