#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int sz = 1e5+1;
int arr[sz];
vector<int> v;
int n, sqr, sum;
vector<pair<pair<int, int>, int>> cmd;
int cnt[1000001];
int result[sz];

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first / sqr != b.first.first / sqr) {
		return a.first.first / sqr < b.first.first / sqr;
	}
	return a.first.second < b.first.second;
}

void add(int x) {
	sum += ((cnt[x]++) == 0);
}

void sub(int x) {
	sum -= ((--cnt[x]) == 0);
}

void solve() {
	cin >> n;
	sqr = (int)sqrt(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
	}

	int m, a, b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cmd.push_back({ {--a,--b},i });
	}
	sort(cmd.begin(), cmd.end(), comp);

	int start = cmd[0].first.first;
	int end = cmd[0].first.second;
	for (int i = start; i <= end; i++) {
		add(arr[i]);
	}
	result[cmd[0].second] = sum;

	for (int i = 1; i < m; i++) {
		auto now = cmd[i];
		while (now.first.first < start) add(arr[--start]);
		while (now.first.first > start) sub(arr[start++]);
		while (now.first.second > end) add(arr[++end]);
		while (now.first.second < end) sub(arr[end--]);
		result[now.second] = sum;
	}

	for (int i = 0; i < m; i++) {
		cout << result[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
