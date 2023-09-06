#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string s;
string colors[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
unsigned long long answer;

int get_value() {
	int index = 0;
	for (auto c : colors) {
		if (c == s) {
			break;
		}
		++index;
	}
	return index;
}

void solve() {
	cin >> s;
	answer = get_value();
	answer *= 10;
	cin >> s;
	answer += get_value();
	cin >> s;
	answer *= pow(10, get_value());
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
