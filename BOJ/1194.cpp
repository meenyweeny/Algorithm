#include<iostream>
#include<queue>
using namespace std;

const char emp = '.';
const char exitdoor = '1';
const char wall = '#';

bool is_door(char c) {
	return c >= 'A' && c <= 'F';
}

bool is_key(char c) {
	return c >= 'a' && c <= 'f';
}

int n, m;
char map[50][50];
pair<int, int> start;
bool visited[50][50][64];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				start = { i,j };
				map[i][j] == emp;
			}
		}
	}
}

bool check_range(int x, int y) {
	return x >= 0 && x < n && y >= 0 & y < m;
}

int solution() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ start,{0,0} });
	visited[start.first][start.second][0] = true;
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int count = q.front().second.first; 
		int key = q.front().second.second;
		q.pop();

		if (map[fx][fy] == exitdoor) {
			return count;
		}

		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';
			int new_key = key;
			if (!check_range(nx, ny)) {
				continue;
			}
			if (map[nx][ny] == wall) {
				continue;
			}
			if (visited[nx][ny][key]) {
				continue;
			}
			if (is_door(map[nx][ny])) {
				int door_index = map[nx][ny] - 'A';
				int door_key = 1 << door_index;
				door_key &= new_key;
				if (!door_key) {
					continue;
				}
			}
			if (is_key(map[nx][ny])) {
				int key_index = map[nx][ny] - 'a';
				int make_key = 1 << key_index;
				new_key |= make_key;
			}
			q.push({ {nx,ny},{count + 1,new_key} });
			visited[nx][ny][new_key] = true;
		}
	}
	return -1;
}

void solve() {
	input();
	cout << solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
