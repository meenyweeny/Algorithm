#include<iostream>
#include<string>
using namespace std;

const int sz = 1e6 + 1;
string str, bomb;
char answer[sz];
int back_index;
int str_size, bomb_size;

bool check_string() {
	int start_point = back_index - bomb_size + 1;
	for (int i = 0; i < bomb.size(); i++) {
		if (bomb[i] != answer[start_point + i]) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> str;
	cin >> bomb;

	str_size = str.size();
	bomb_size = bomb.size();

	for (int i = 0; i < str_size; i++) {
		char ch = str[i];
		answer[back_index] = ch;
		if (answer[back_index] == bomb[bomb_size -1] && back_index>= bomb_size -1) {
			if (check_string()) {
				back_index -= bomb_size;
			}
		}
		++back_index;
		answer[back_index] = 0;
	}

	if (!back_index) {
		cout << "FRULA";
	} else {
		cout << answer;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
