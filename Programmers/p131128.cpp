#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

string x, y;
int mx[10];
int my[10];

void solve() {
	cin >> x >> y;
	for (auto q : x) {
		++mx[q - '0'];
	}
	for (auto q : y) {
		++my[q - '0'];
	}
	string s = "";
	for (int i = 9; i > 0; i--) {
		int count = min(mx[i], my[i]);
		for (int j = 0; j < count; j++) {
			s += to_string(i);
		}
	}
	int count = min(mx[0], my[0]);
	if (s == "" && count > 0) {
		s = "0";
	} else {
		for (int j = 0; j < count; j++) {
			s += "0";
		}
	}
	if (s == "") {
		cout << -1;
	} else {
		cout << s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
