#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int sz = 1e2;
int n, m;
char map[sz][sz];
bool visited[sz][sz];

bool check_range(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void solve() {
	cin >> n >> m;
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j];
		}
	}

	queue<pair<int,pair<int, int>>> q;
	q.push({ 1, {0,0} });
	visited[0][0] = true;

	while (!q.empty()) {
		int count = q.front().first + 1;
		int fx = q.front().second.first;
		int fy = q.front().second.second;
		q.pop();

		if (fx == n - 1 && fy == m - 1) {
			cout << count - 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = fx + "2011"[i] - '1';
			int ny = fy + "1120"[i] - '1';
			if (!check_range(nx, ny)) {
				continue;
			}
			if (visited[nx][ny]) {
				continue;
			}
			if (map[nx][ny]=='0') {
				visited[nx][ny] = true;
				continue;
			}
			
			visited[nx][ny] = true;
			q.push({ count, {nx,ny} });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
