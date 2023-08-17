#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct point {
	int x, y;
};

int n, answer;
pair<int, int> company;
pair<int, int> home;
pair<int, int> customer[10];
bool visited[10];

void init() {
	answer = 2e9;
	fill(visited, visited + 10, false);
}

int get_dist(pair<int, int> s, pair<int, int> d) {
	return abs(s.first - d.first) + abs(s.second - d.second);
}

void input() {
	cin >> n;
	cin >> company.first >> company.second;
	cin >> home.first >> home.second;
	for (int i = 0; i < n; i++) {
		cin >> customer[i].first >> customer[i].second;
	}
}

void run(int count, int sum, pair<int,int> before) {
	if (answer < sum) {
		return;
	}

	if (count == n) {
		sum += get_dist(before, home);
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		run(count + 1, sum + get_dist(before, customer[i]), customer[i]);
		visited[i] = false;
	}
}

void solve() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		run(0, 0, company);
		cout << '#' << tc << ' ' << answer << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}

