#include<iostream>
#include<string>
#include<deque>
#include<queue>
using namespace std;

string bomb, str;
int small[26], big[26], num[10];
deque<pair<char,bool>> dq;

void init() {
	for (int i = 0; i < bomb.length(); i++) {
		char ch = bomb[i];
		if (ch >= 'A' && ch <= 'Z') {
			big[ch - 'A'] = i + 1;
		} else if (ch >= 'a' && ch <= 'z') {
			small[ch - 'a'] = i + 1;
		} else {
			num[ch - '0'] = i + 1;
		}
	}
}

int get_index_value(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return big[ch - 'A'];
	} else if (ch >= 'a' && ch <= 'z') {
		return small[ch - 'a'];
	} else {
		return num[ch - '0'];
	}
}

bool check_string() {
	pair<char, bool> before;
	before = dq.back();
	if (get_index_value(before.first) == bomb.size() && before.second) {
		for (int i = 0; i < bomb.size(); i++) {
			dq.pop_back();
		}
		return true;
	} else {
		return false;
	}
}

void solve() {
	cin >> str;
	cin >> bomb;
	init();
	int value;
	pair<char, bool> before;
	for (auto s : str) {
		value = get_index_value(s);
		if (dq.empty()) {
			dq.push_back({ s, value == 1 });
		}
		else {
			if (!value) {
				dq.push_back({ s,false });
			} else {
				before = dq.back();
				bool flag = value == 1 ? 1 : (get_index_value(before.first) + 1 == value && before.second);
				dq.push_back({ s, flag });
			}
		}
		check_string();
	}

	if (dq.empty()) {
		cout << "FRULA";
	} else {
		while (!dq.empty()) {
			cout << dq.front().first;
			dq.pop_front();
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
