#include<iostream>
#include<deque>
using namespace std;

const int sz = 1e5 + 1;
int n, k;
bool visited[sz];

int bfs() {
	deque<pair<int, int>> q;
	q.push_back({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int fx = q.front().first;
		int cnt = q.front().second;
		q.pop_front();

		if (fx == k) {
			return cnt;
		}

		if ((fx*2< sz) && !visited[fx * 2]) {
			visited[fx * 2] = true;
			q.push_front({ fx * 2,cnt });
		}
		if (!visited[fx - 1]) {
			visited[fx - 1] = true;
			q.push_back({ fx - 1,cnt + 1 });
		}
		if ((fx+1< sz)&&!visited[fx + 1]) {
			visited[fx + 1] = true;
			q.push_back({ fx + 1,cnt + 1 });
		}
	}
	return -1;
}

void solve() {
	cin >> n >> k;
	cout << bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
