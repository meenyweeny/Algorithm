#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, answer;
int map[8][8];
bool visited[8][8];
vector<pair<int, int>> virus;
int wall = 3;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			} else if (map[i][j] == 1) {
				++wall;
			}
		}
	}
}

bool check_range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int get_safearea() {
	int harm = virus.size();
	queue<pair<int, int>> q;
	fill(&visited[0][0], &visited[7][8], false);
	for (auto v : virus) {
		q.push(v);
		visited[v.first][v.second] = true;
	}
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
			if (visited[nx][ny]) {
				continue;
			}
			if (map[nx][ny]>0) {
				continue;
			}
			visited[nx][ny] = true;
			++harm;
			q.push({ nx,ny });
		}
	}

	return n * m - harm - wall;
}

void process(int count, int x, int y) {
	if (count == 3) {
		answer = max(answer, get_safearea());
		return;
	}
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]!=0) {
				continue;
			}
			map[i][j] = 1;
			process(count + 1, i, j + 1);
			map[i][j] = 0;
		}
	}
}

void solve() {
	input();
	process(0, 0, 0);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
