#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int sz = 1e2;
int m, n, k;
bool map[sz][sz];

bool check_range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int x, int y) {
	deque<pair<int, int>> q;
	int count = 0;
	q.push_back({ x,y });
	map[x][y] = true;
	
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop_front();
		++count;

		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';
			if (!check_range(nx, ny)) {
				continue;
			}
			if (map[nx][ny]) {
				continue;
			}
			map[nx][ny] = true;
			q.push_back({ nx,ny });
		}
	}

	return count;
}

void solve() {
	cin >> m >> n >> k;
	int x, y, xx, yy;
	while (k--) {
		cin >> x >> y >> xx >> yy;
		for (int i = x; i < xx; i++) {
			for (int j = y; j < yy; j++) {
				map[i][j] = true;
			}
		}
	}
	
	deque<int> path;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				continue;
			}
			path.push_back(bfs(i, j));
		}
	}

	cout << path.size() << '\n';
	sort(path.begin(), path.end());
	for (auto p : path) {
		cout << p << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
