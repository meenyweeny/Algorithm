#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e4;
int r, c, answer;
char map[sz][500];

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
}

bool check_range(int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

bool run(int x, int y) {
    if (y == c-1) {
        ++answer;
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        int nx = x + "012"[i] - '1';
        int ny = y + 1;
        if (!check_range(nx, ny)) {
            continue;
        }
        if (map[nx][ny] != '.') {
            continue;
        }
        map[nx][ny] = 'p';
        if(run(nx, ny)) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    input();
    for(int i=0; i<r; i++) {
        run(i,0);
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
