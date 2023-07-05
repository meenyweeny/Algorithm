#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int n, w, l;
queue<int> car;
deque<pair<int, int>> bridge;
int weight, answer;

void input() {
	cin >> n >> w >> l;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		car.push(k);
	}
}

void process() {
	for (int i = 0; i < bridge.size(); i++) {
		bridge[i].second += 1;
	}
	if (bridge.front().second == w) {
		weight -= bridge.front().first;
		bridge.pop_front();
	}
	++answer;
}


void solution() {
	while (!car.empty()) {
		if (car.front() <= (l - weight)) {
			bridge.push_back({ car.front(),0 });
			weight += car.front();
			car.pop();
		}
		process();
	}
	while (!bridge.empty()) {
		process();
	}
	cout << answer+1;
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
