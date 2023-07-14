#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int l, c;
char arr[15];

bool is_vowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void process(string password, bool has_vowel, int consonant_count, int start) {
	if (password.size() == l) {
		if (has_vowel && consonant_count >= 2) {
			cout << password << '\n';
		}
		return;
	}
	for (int i = start; i < c; i++) {
		char ch = arr[i];
		bool vowel = is_vowel(ch);
		process(password + ch, has_vowel||vowel, consonant_count + (!vowel), i + 1);
	}
}

void solve() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	process("", false, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
