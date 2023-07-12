#include<iostream>
#include<stack>
using namespace std;

const int sz = 1e6 + 1;
int n;
int arr[sz];
int f[sz];
stack<pair<int, int>> st;
stack<int> answer;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		++f[arr[i]];
	}
}

void solution() {
	reverse(arr + 1, arr + n+1);
	for (int i = 1; i <= n; i++) {
		pair<int, int> now = { arr[i],f[arr[i]] };
		while (!st.empty()) {
			if (st.top().second > now.second) {
				break;
			} else {
				st.pop();
			}
		}
		if (st.empty()) {
			answer.push(-1);
		} else {
			answer.push(st.top().first);
		}
		st.push(now);
	}

	while (!answer.empty()) {
		cout << answer.top() << ' ';
		answer.pop();
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
