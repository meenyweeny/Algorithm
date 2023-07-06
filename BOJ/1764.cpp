#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<string> v;
vector<string> answer;

void solve() {
	cin >> n >> m;
	string str;
	while (n--) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	while (m--) {
		cin >> str;
		if (binary_search(v.begin(), v.end(), str)) {
			answer.push_back(str);
		}
	}
	sort(answer.begin(), answer.end());
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
