#include<iostream>
#include<queue>
using namespace std;

const int sz = 1e3;
int n, m;
int map[sz][sz];
queue<pair<pair<int, int>, int>> q;

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs() {
	int answer = 0;
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int count = q.front().second + 1;
		answer = count-1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';

			if (!check_range(nx, ny)) {
				continue;
			}
			if (map[nx][ny]==1 || map[nx][ny]==-1) {
				continue;
			}
			map[nx][ny] = 1;
			q.push({ {nx,ny},count });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				return -1;
			}
		}
	}
	return answer;
}

void solve() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ {i,j},0 });
			}
		}
	}
	cout<<bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
