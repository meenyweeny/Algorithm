#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int n, nxt;
queue<int> student;
stack<int> order;

void solve() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		student.push(k);
	}

	order.push(student.front());
	student.pop();
	nxt = 1;
	while (!student.empty()) {
		if (student.front() == nxt) {
			++nxt;
			student.pop();
			continue;
		}
		if (!order.empty() && order.top() == nxt) {
			++nxt;
			order.pop();
		} else {
			order.push(student.front());
			student.pop();
		}
	}
	while (!order.empty()) {
		if (order.top() == nxt) {
			order.pop();
			++nxt;
		} else {
			break;
		}
	}

	cout << (order.empty() ? "Nice" : "Sad");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
