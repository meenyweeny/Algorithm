#include<iostream>
#include<queue>
using namespace std;

int n, m;
bool map[50][50];

void init() {
	fill(&map[0][0], &map[49][50], false);
}

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = false;

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
			if (!map[nx][ny]) {
				continue;
			}
			q.push({ nx,ny });
			map[nx][ny] = false;
		}
	}
}

void solve() {
	int t, k, x, y;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		while (k--) {
			cin >> y >> x;
			map[x][y] = true;
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					bfs(i, j);
					++answer;
				}
			}
		}
		cout << answer << '\n';
		init();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
