#include<iostream>
#include<string>
using namespace std;

const char plain = '.';
const char brick = '*';
const char iron = '#';
const char water = '-';
int h, w;
char map[20][20];
string cmd;
pair<int, int> now;
pair<int, int> dir;

void input() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '<') {
				now = { i,j };
				dir = { 0, -1 };
			}
			else if (map[i][j] == '^') {
				now = { i,j };
				dir = { -1, 0 };
			}
			else if (map[i][j] == 'v') {
				now = { i,j };
				dir = { 1, 0 };
			}
			else if (map[i][j] == '>') {
				now = { i,j };
				dir = { 0, 1 };
			}
		}
	}
	cin >> cmd;
	cin >> cmd;
}

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

void move() {
	int nx = now.first + dir.first;
	int ny = now.second + dir.second;

	if (!check_range(nx, ny)) {
		return;
	}
	if (map[nx][ny] == plain) {
		map[now.first][now.second] = plain;
		now = { nx,ny };
	}
}

void shoot() {
	int nx = now.first;
	int ny = now.second;
	while (1) {
		nx += dir.first;
		ny += dir.second;
		if (!check_range(nx, ny)) {
			break;
		}
		if (map[nx][ny] == iron) {
			break;
		}
		if (map[nx][ny] == brick) {
			map[nx][ny] = plain;
			break;
		}
	}
}

void solution() {
	for (auto c : cmd) {
		if (c == 'U') {
			dir = { -1,0 };
			move();
		} else if (c == 'D') {
			dir = { 1,0 };
			move();
		} else if (c == 'L') {
			dir = { 0,-1 };
			move();
		} else if (c == 'R') {
			dir = { 0,1 };
			move();
		} else {
			shoot();
		}
	}

	char car;
	if (dir.first == -1) {
		car = '^';
	} else if (dir.first == 1) {
		car = 'v';
	} else if (dir.second == 1) {
		car = '>';
	} else {
		car = '<';
	}
	map[now.first][now.second] = car;
}

void output() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void solve() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		input();
		solution();
		cout << '#' << tc << ' ';
		output();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
