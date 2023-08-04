#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int sz = 1e6 + 1;
int arr[sz];
int cnt[sz];
int res[sz];
int n, sqr, sum;
vector<int> c;
vector<pair<pair<int, int>, int>> cmd;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first / sqr != b.first.first/sqr) {
		return a.first.first / sqr < b.first.first / sqr;
	}
	return a.first.second < b.first.second;
}

void add(int x) {
	if (!cnt[x]) {
		++sum;
	}
	++cnt[x];
}

void sub(int x) {
	--cnt[x];
	if (!cnt[x]) {
		--sum;
	}
}

void solve() {
	cin >> n;
	sqr = (int)sqrt(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		c.push_back(arr[i]);
	}

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(c.begin(), c.end(), arr[i]) - c.begin();
	}

	int q, a, b;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cmd.push_back({ {--a,--b},i });
	}
	sort(cmd.begin(), cmd.end(), comp);

	int start = cmd[0].first.first;
	int end = cmd[0].first.second;
	for (int i = start; i <= end; i++) {
		add(arr[i]);
	}
	res[cmd[0].second] = sum;

	for (int i = 1; i < q; i++) {
		auto now = cmd[i];
		while (now.first.first < start) {
			add(arr[--start]);
		}
		while (now.first.second > end) {
			add(arr[++end]);
		}
		while (now.first.first > start) {
			sub(arr[start++]);
		}
		while (now.first.second < end) {
			sub(arr[end--]);
		}
		res[now.second] = sum;
	}
	for (int i = 0; i < q; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
