#include<iostream>
#include<queue>
using namespace std;

int n, answer;
priority_queue<int, vector<int>, less<int>> pos;
priority_queue<int, vector<int>, greater<int>> neg;

void input() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k <= 0) {
			neg.push(k);
		}
		else {
			pos.push(k);
		}
	}
}

void solution() {
	int a, b, value;
	while (pos.size() > 1) {
		a = pos.top();
		pos.pop();
		b = pos.top();
		pos.pop();
		value = a * b > a + b ? a * b : a + b;
		answer += (value);
	}
	if (!pos.empty()) {
		answer += pos.top();
	}

	while (neg.size() > 1) {
		a = neg.top();
		neg.pop();
		b = neg.top();
		neg.pop();
		value = a * b > a + b ? a * b : a + b;
		answer += (value);
	}
	if (!neg.empty()) {
		answer += neg.top();
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
