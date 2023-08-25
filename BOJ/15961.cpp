#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int sz = 3e6;
int n, d, k, c, answer;
int arr[sz];
int visited[3001];

void input() {
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int species = 1;
	visited[c] = 1;
	int start = 0;
	int end = k - 1;
	for (int i = 0; i <= end; i++) {
		if (!visited[arr[i]]) {
			++species;
		}
		++visited[arr[i]];
	}
	answer = species;
	while (start <= n) {
		--visited[arr[start%n]];
		if (!visited[arr[start%n]]) {
			--species;
		}
		++start;
		++end;
		if (!visited[arr[end%n]]) {
			++species;
		}
		++visited[arr[end%n]];
		answer = max(answer, species);
	}
	cout << answer;
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
