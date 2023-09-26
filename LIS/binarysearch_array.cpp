#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int sz = 1e6;
int n;
int arr[sz];
int idx[sz];
vector<int> lis;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > lis.back()) {
			idx[i] = lis.size();
			lis.push_back(arr[i]);
		} else {
			int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[index] = arr[i];
			idx[i] = index;
		}
	}
	int length = lis.size() - 1;
	vector<int> path;
	for (int i = n-1; i >= 0; i--) {
		if (idx[i] == length) {
			path.push_back(arr[i]);
			--length;
		}
	}
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (auto p : path) {
		cout << p << ' ';
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
