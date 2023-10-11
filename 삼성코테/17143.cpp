#include<iostream>
#include<vector>
using namespace std;

struct Shark {
	int x, y, speed, dx, dy, size;
};

const int sz = 1e2;
int r, c, m, answer, fishking;
int map[sz][sz];
Shark info[sz*sz + 1];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> pos[sz][sz];

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			pos[i][j].clear();
		}
	}
}

void input() {
	cin >> r >> c >> m;
	int x, y, s, d, z;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> s >> d >> z;
		--x;
		--y;
		--d;
		map[x][y] = i;
		info[i] = { x,y,s,dx[d],dy[d],z };
	}
}

bool check_range(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

void get_fish() {
	int got = 0;
	for (int i = 0; i < r; i++) {
		if (map[i][fishking] != 0) {
			answer += info[map[i][fishking]].size;
			info[map[i][fishking]] = { 0,0,0,0,0,0 };
			map[i][fishking] = 0;
			break;
		}
	}
}

void move(int x,int y,int index) {
	Shark sh = info[index];
	int nx = x;
	int ny = y;
	if (sh.dx == 0) { //가로 이동
		int cols = c * 2 - 2;
		int iter = sh.speed % cols;
		while(iter>0) {
			if (!check_range(nx, ny + info[index].dy)) {
				info[index].dy *= -1;
			} else {
				ny += info[index].dy;
				--iter;
			}
		}
	} else { //세로 이동
		int rows = r * 2 - 2;
		int iter = sh.speed % rows;
		while (iter>0) {
			if (!check_range(nx + info[index].dx, ny)) {
				info[index].dx *= -1;
			} else {
				nx += info[index].dx;
				--iter;
			}
		}
	}
	//이동할 위치를 찾은 것이 nx,ny에 담겨있다
	pos[nx][ny].push_back(index);
}

void move_fish() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!map[i][j]) {
				continue;
			}
			move(i,j,map[i][j]);
		}
	}
}

void arrange_map() {
	fill(&map[0][0], &map[sz-1][sz], 0);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (pos[i][j].empty()) {
				continue;
			} else if (pos[i][j].size() == 1) {
				map[i][j] = pos[i][j][0];
			} else {
				map[i][j] = pos[i][j][0];
				int now_index = map[i][j];
				int now_size = info[now_index].size;
				for (int idx = 1; idx < pos[i][j].size(); idx++) {
					int next_index = pos[i][j][idx];
					if (info[next_index].size > now_size) {
						info[now_index] = { 0,0,0,0,0,0 };
						map[i][j] = next_index;
						now_size = info[next_index].size;
						now_index = next_index;
					} else {
						info[next_index] = { 0,0,0,0,0,0 };
					}
				}
			}
		}
	}
}

void solution() {
	while(fishking < c) {
		get_fish();
		init();
		move_fish();
		arrange_map();
		++fishking;
	}
	cout << answer;
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
