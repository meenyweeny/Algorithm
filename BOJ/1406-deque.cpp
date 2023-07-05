#include<iostream>
#include<string>
#include<deque>
using namespace std;

deque<char> lhs, rhs;

void solve() {
	string str;
	cin >> str;

	for (auto s : str) {
		lhs.push_back(s);
	}

	int m;
	char a;
	cin >> m;

	while (m--) {
		cin >> a;
		if (a == 'P') {
			cin >> a;
			lhs.push_back(a);
		} else if (a == 'L' && !lhs.empty()) {
			rhs.push_front(lhs.back());
			lhs.pop_back();
		} else if (a == 'D' && !rhs.empty()) {
			lhs.push_back(rhs.front());
			rhs.pop_front();
		} else if (a == 'B' && !lhs.empty()) {
			lhs.pop_back();
		}
	}

	for (auto l : lhs) {
		cout << l;
	}
	for (auto r : rhs) {
		cout << r;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
