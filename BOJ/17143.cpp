#include<iostream>
#include<deque>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

struct Shark {
	int speed, dirx, diry, size;

	bool operator<(const Shark & b) const {
		return size < b.size;
	}
};

int r, c, m, answer;
Shark matrix[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
Shark tmp = { 0,0,0,-1 };
map<pair<int, int>, Shark> next_move;
deque<pair<int, int>> loc;

bool comp(Shark a, Shark b) {
	if (a.dirx == b.dirx) {
		if (a.diry == b.diry) {
			return a.size > b.size;
		}
		else {
			return a.diry > b.diry;
		}
	}
	else {
		return a.dirx > b.dirx;
	}
}

void input() {
	cin >> r >> c >> m;
	int x, y, s, d, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cin >> s >> d >> z;
		--x; --y; --d;
		matrix[x][y] = { s,dx[d],dy[d],z };
		loc.push_back({ x,y });
	}
}

bool is_border(int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

pair<pair<int, int>, Shark> get_next_location(int x, int y) {
	int nx = x;
	int ny = y;
	int dx = matrix[x][y].dirx;
	int dy = matrix[x][y].diry;
	int size = matrix[x][y].size;
	int speed = matrix[x][y].speed;
	if (dx == 0) {
		speed %= ((c - 1) * 2);
	} else if (dy == 0) {
		speed %= ((r - 1) * 2);
	}

	for (int i = 0; i < speed; i++) {
		if (is_border(nx + dx, ny + dy)) {
			nx += dx; ny += dy;
		}
		else {
			dx = -dx; dy = -dy;
			--i;
		}
	}
	return { {nx,ny}, {speed,dx,dy,size} };
}

void move_shark() {
	next_move.clear();
	int size = loc.size();
	for (int i = 0; i < size; i++) {
		int fx = loc[i].first;
		int fy = loc[i].second;
		if (matrix[fx][fy].size == -1) {
			continue;
		}
		pair<pair<int, int>, Shark> next = get_next_location(fx, fy);
		Shark now = next.second;
		pair<int, int> f = next.first;
		next_move[{f.first, f.second}] = max(next_move[{f.first, f.second}], now);
	}
	loc.clear();
	fill(&matrix[0][0], &matrix[99][100], tmp);
	for (auto s : next_move) {
		matrix[s.first.first][s.first.second] = next_move[s.first];
		loc.push_back({ s.first.first, s.first.second });
	}
}

void solution() {
	int col = 0;
	if (m == 0) {
		cout << answer;
		return;
	}
	while (col < c) {
		for (int i = 0; i < r; i++) {
			if (matrix[i][col].size == -1) {
				continue;
			}
			else {
				answer += matrix[i][col].size;
				matrix[i][col] = tmp;
				break;
			}
		}
		move_shark();
		++col;
	}
	cout << answer;
}

void solve() {
	fill(&matrix[0][0], &matrix[99][100], tmp);
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
