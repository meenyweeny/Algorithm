#include<iostream>
#include<deque>
#include<cmath>
using namespace std;

int k;
deque<char> arr[4];
int spindir[4];

void input() {
	char ch;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch;
			arr[i].push_back(ch);
		}
	}
}

void spin(int num, int dir) {
	if (dir == 1) {
		arr[num].push_front(arr[num].back());
		arr[num].pop_back();
	} else if(dir==-1) {
		arr[num].push_back(arr[num].front());
		arr[num].pop_front();
	}
}

void make_spin(int num) {
	int tmp = num;
	while (1) {
		if (num == 3) {
			break;
		}
		if (arr[num][2] != arr[num + 1][6]) {
			spindir[num + 1] = spindir[num] * -1;
		} else{
			break;
		}
		++num;
	}
	num = tmp;
	while (1) {
		if (num == 0) {
			break;
		}
		if (arr[num][6] != arr[num - 1][2]) {
			spindir[num-1] = spindir[num] * -1;
		} else {
			break;
		}
		--num;
	}
}

void solve() {
	input();
	cin >> k;
	int num, dir;
	while (k--) {
		cin >> num >> dir;
		--num;
		fill(spindir, spindir + 4, 0);
		spindir[num] = dir;
		make_spin(num);
		for (int i = 0; i < 4; i++) {
			spin(i, spindir[i]);
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] != '0') {
			answer += pow(2, i);
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
}
