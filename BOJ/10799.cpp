#include<iostream>
#include<string>
#include<vector>
using namespace std;

int answer, stick;

void solve() {
	string str;
	cin >> str;

	int length = str.size();
	for (int i = 0; i < length; i++) {
		if (str[i] == '(') {
			++stick;
		} else {
			if (str[i - 1] == '(') {
				answer += (--stick);
			}
			else {
				--stick;
				++answer;
			}
		}
	}
	answer += stick;
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
