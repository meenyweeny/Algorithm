#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> s;

void solve() {
	int n;
	cin >> n;
	string cmd;
	int answer = 0;
	while (n--) {
		cin >> cmd;
		if (cmd == "ENTER") {
			s.clear();
		} else {
			answer += s.insert(cmd).second;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();
}
