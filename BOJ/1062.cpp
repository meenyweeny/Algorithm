#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n, k, answer = -1;
vector<string> dict;
int checked;

void init() {
	char arr[5] = {'a', 'c', 'i', 'n', 't'};
	for (auto a : arr) {
		int now = (1 << (a - 'a'));
		checked |= now;
	}
}

void check_string(int comp) {
	int now = 0;
	int bit;
	bool is_on;
	for (auto s : dict) {
		is_on = true;
		for (int i = 4; i < s.length() - 4; i++) {
			bit = (1 << (s[i] - 'a'));
			is_on = comp & bit;
			if (!is_on) {
				break;
			}
		}
		now += is_on;
	}
	answer = max(answer, now);
}

void process(int start, int count, int comp) {
	if (count == k) {
		check_string(comp);
		return;
	}

	for (int i = start; i < 26; i++) {
		int bit = (1 << i);
		if (comp & bit) {
			continue;
		}
		int tmp = comp;
		tmp |= bit;
		process(i + 1, count + 1, tmp);
		tmp = comp;
	}
}

void solve() {
	cin >> n >> k;
	string cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		dict.push_back(cmd);
	}
	if (k < 5) {
		cout << 0;
	} else {
		init();
		k -= 5;
		process(1,0,checked);
		cout << answer;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
