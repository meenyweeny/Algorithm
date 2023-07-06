#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, h, t, k, cnt;
string answer = "NO";
priority_queue<int,vector<int>,less<int>> pq;

void solve() {
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		cin >> k;
		pq.push(k);
	}

	while (t--) {
		if (pq.top() < h) {
			break;
		}
		int top = pq.top();
		pq.pop();
		pq.push(top == 1 ? 1 : top / 2);
		++cnt;
	}
	if (pq.top() < h) {
		answer = "YES";
	}
	if (answer == "YES") {
		cout << answer << '\n' << cnt;
	} else {
		cout << answer << '\n' << pq.top();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
