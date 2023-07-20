#include<iostream>
#include<vector>
using namespace std;

int k;
int arr[13];
vector<int> lotto;

void process(int start) {
	if (lotto.size() == 6) {
		for (auto l : lotto) {
			cout << l << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		lotto.push_back(arr[i]);
		process(i + 1);
		lotto.pop_back();
	}
}

void solve() {
	cin >> k;
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		lotto.clear();
		process(0);
		cout << '\n';
		cin >> k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
