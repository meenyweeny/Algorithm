#include<iostream>
#include<string>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

int n, m;
unordered_set<string> s;
set<string> answer;

void solve() {
	cin >> n >> m;
	string str;
	while (n--) {
		cin >> str;
		s.insert(str);
	}
	while (m--) {
		cin >> str;
		if (s.count(str)) {
			answer.insert(str);
		}
	}
	cout << answer.size() << '\n';
	for (auto a : answer) {
		cout << a << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
