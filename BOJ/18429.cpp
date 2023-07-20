#include<iostream>
using namespace std;

int n, k, answer;
int weight[50];
bool visited[50];

void process(int count, int total) {
	if (count == n) {
		++answer;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		if (total - k + weight[i] < 500) {
			continue;
		}
		visited[i] = true;
		process(count + 1, total - k + weight[i]);
		visited[i] = false;
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	process(0, 500);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
