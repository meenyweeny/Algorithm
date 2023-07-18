#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, k, answer, checked;
int arr[50];

void init() {
	char ch[5] = { 'a','n','t','i','c' };
	for (auto c : ch) {
		checked |= (1 << (c - 'a'));
	}
}

int compare(int comp) {
	int now = 0;
	for (int i = 0; i < n; i++) {
		now += ((comp | arr[i]) == comp);
	}
	return now;
}

void process(int comp, int start, int count) {
	if (count == k) {
		answer = max(answer,compare(comp));
		return;
	}
	int bit;
	for (int i = start; i < 26; i++) {
		bit = 1 << i;
		if (comp & bit) {
			continue;
		}
		comp |= bit;
		process(comp, i + 1, count + 1);
		comp &= ~bit;
	}
}

void solve() {
	cin >> n >> k;
	string cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		for (auto c : cmd) {
			arr[i] |= (1 << (c - 'a'));
		}
	}
	k -= 5;
	if (k >= 0) {
		init();
		process(checked, 0, 0);
	}
	cout << answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
