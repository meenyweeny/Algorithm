#include<iostream>
#include<queue>
using namespace std;

const int inf = 1e9;
int n;
bool map[16][16];
int dp[16][16];
int dir = 0;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool checkRange(int x, int y, int d) {
	return x >= 0 && x < (n - dx[d]) && y >= 0 && y < (n - dy[d]);
}

void solution() {
	dp[0][1] = 1;
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {0,1},{0,1} });
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		bool flag = true;
		if (d == 0) {
			for (auto nd : { 0,2 }) {
				flag = true;
				if (checkRange(fx, fy, nd)) {
					if (map[fx + dx[nd]][fy + dy[nd]]) {
						flag = false;
						continue;
					}
					if (nd == 2) {
						for (auto i : { 0,1 }) {
							if (map[fx + dx[i]][fy + dy[i]]) {
								flag = false;
								break;
							}
						}
					}
					if (!flag) {
						continue;
					}
					dp[fx + dx[nd]][fy + dy[nd]] += cnt;
					q.push({ {fx + dx[nd],fy + dy[nd]},{nd,cnt} });
				}
			}
		} else if (d == 1) {
			for (auto nd : { 1,2 }) {
				flag = true;
				if (checkRange(fx, fy, nd)) {
					if (map[fx + dx[nd]][fy + dy[nd]]) {
						flag = false;
						continue;
					}
					if (nd == 2) {
						for (auto i : { 0,1 }) {
							if (map[fx + dx[i]][fy + dy[i]]) {
								flag = false;
								break;
							}
						}
					}
					if (!flag) {
						continue;
					}
					dp[fx + dx[nd]][fy + dy[nd]] += cnt;
					q.push({ {fx + dx[nd],fy + dy[nd]},{nd,cnt} });
				}
			}
		} else {
			for (auto nd : { 0,1,2 }) {
				flag = true;
				if (checkRange(fx, fy, nd)) {
					if (map[fx + dx[nd]][fy + dy[nd]]) {
						flag = false;
						continue;
					}
					if (nd == 2) {
						for (auto i : { 0,1 }) {
							if (map[fx + dx[i]][fy + dy[i]]) {
								flag = false;
								break;
							}
						}
					}
					if (!flag) {
						continue;
					}
					dp[fx + dx[nd]][fy + dy[nd]] += cnt;
					q.push({ {fx + dx[nd],fy + dy[nd]},{nd,cnt} });
				}
			}
		}
	}

	cout << dp[n - 1][n - 1];
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
