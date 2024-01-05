#include<iostream>
#include<vector>
using namespace std;

int n, m;
int map[8][8];
int answer = 2e9;
int dy[3] = { -1,0,1 };

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

void run(int before_direction, int sum, int bx, int by) {
    if (bx == n) {
        answer = min(answer, sum);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (before_direction == i) {
            continue;
        }
        int nx = bx + 1;
        int ny = by + dy[i];
        if (ny < 0 || ny >= m) {
            continue;
        }
        run(i, sum + map[nx][ny], nx, ny);
    }
}

void solve() {
    input();
    for (int i = 0; i < m; i++) {
        int nx = 1;
        int ny = i;
        for (int j = 0; j < 3; j++) {
            ny = i + dy[j];
            if (ny < 0 || ny >= m) {
                continue;
            }
            run(j, map[nx][ny], nx, ny);
        }
    }
    cout << answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
