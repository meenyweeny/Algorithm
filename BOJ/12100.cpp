#include<iostream>
#include<vector>

using namespace std;

struct Point {
    int x, y;
};

int n, answer;
int map[22][22];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
}

bool is_in_range(Point p) {
    return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= n;
}

void process(int count, int before, int board[22][22]) {
    Point now, up;
    vector<int> v;

    int tmp[22][22];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[i][j] = board[i][j];
        }
    }

    if (before == 1) {
        for (int i = 1; i <= n; i++) {
            up.x = 1;
            up.y = i;
            now.x = 2;
            now.y = i;
            while (1) {
                if (!is_in_range(now)) {
                    break;
                }
                if (tmp[now.x][now.y] == 0) {
                    ++now.x;
                    continue;
                } else if (tmp[now.x][now.y] != tmp[up.x][up.y]) {
                    up.x = now.x;
                    up.y = now.y;
                } else {
                    tmp[up.x][up.y] *= 2;
                    tmp[now.x][now.y] = 0;
                    up.x = now.x;
                    up.y = now.y;
                }
                ++now.x;
            }
        }
        for (int i = 1; i <= n; i++) {
            v.clear();
            for (int j = 1; j <= n; j++) {
                if (tmp[j][i] != 0) {
                    v.push_back(tmp[j][i]);
                }
            }
            int v_size = v.size();
            for (int j = 1; j <= v_size; j++) {
                tmp[j][i] = v[j - 1];
            }
            for (int j = v_size + 1; j <= n; j++) {
                tmp[j][i] = 0;
            }
        }
    } else if(before==2) {
        for (int i = 1; i <= n; i++) {
            up.x = n;
            up.y = i;
            now.x = n-1;
            now.y = i;
            while (1) {
                if (!is_in_range(now)) {
                    break;
                }
                if (tmp[now.x][now.y] == 0) {
                    --now.x;
                    continue;
                } else if (tmp[now.x][now.y] != tmp[up.x][up.y]) {
                    up.x = now.x;
                    up.y = now.y;
                } else {
                    tmp[up.x][up.y] *= 2;
                    tmp[now.x][now.y] = 0;
                    up.x = now.x;
                    up.y = now.y;
                }
                --now.x;
            }
        }
        for (int i = 1; i <= n; i++) {
            v.clear();
            for (int j = n; j >= 1; j--) {
                if (tmp[j][i] != 0) {
                    v.push_back(tmp[j][i]);
                }
            }
            int v_size = v.size();
            int index = 0;
            for (int j = n; j >= n-v_size+1; j--) {
                tmp[j][i] = v[index];
                ++index;
            }
            for (int j = n-v_size; j >=1; j--) {
                tmp[j][i] = 0;
            }
        }
    } else if (before == 3) {
        for (int i = 1; i <= n; i++) {
            up.x = i;
            up.y = 1;
            now.x = i;
            now.y = 2;
            while (1) {
                if (!is_in_range(now)) {
                    break;
                }
                if (tmp[now.x][now.y] == 0) {
                    ++now.y;
                    continue;
                } else if (tmp[now.x][now.y] != tmp[up.x][up.y]) {
                    up.x = now.x;
                    up.y = now.y;
                } else {
                    tmp[up.x][up.y] *= 2;
                    tmp[now.x][now.y] = 0;
                    up.x = now.x;
                    up.y = now.y;
                }
                ++now.y;
            }
        }
        for (int i = 1; i <= n; i++) {
            v.clear();
            for (int j = 1; j <= n; j++) {
                if (tmp[i][j] != 0) {
                    v.push_back(tmp[i][j]);
                }
            }
            int v_size = v.size();
            for (int j = 1; j <= v_size; j++) {
                tmp[i][j] = v[j - 1];
            }
            for (int j = v_size + 1; j <= n; j++) {
                tmp[i][j] = 0;
            }
        }
    } else if (before==4) {
        for (int i = 1; i <= n; i++) {
            up.x = i;
            up.y = n;
            now.x = i;
            now.y = n-1;
            while (1) {
                if (!is_in_range(now)) {
                    break;
                }
                if (tmp[now.x][now.y] == 0) {
                    --now.y;
                    continue;
                } else if (tmp[now.x][now.y] != tmp[up.x][up.y]) {
                    up.x = now.x;
                    up.y = now.y;
                } else {
                    tmp[up.x][up.y] *= 2;
                    tmp[now.x][now.y] = 0;
                    up.x = now.x;
                    up.y = now.y;
                }
                --now.y;
            }
        }
        for (int i = 1; i <= n; i++) {
            v.clear();
            for (int j = n; j >= 1; j--) {
                if (tmp[i][j] != 0) {
                    v.push_back(tmp[i][j]);
                }
            }
            int v_size = v.size();
            int index = 0;
            for (int j = n; j >= n-v_size+1; j--) {
                tmp[i][j] = v[index];
                ++index;
            }
            for (int j = n-v_size; j >= 1; j--) {
                tmp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            answer = max(answer, tmp[i][j]);
        }
    }
    if (count == 5) {
        return;
    }
    for (int i = 1; i < 5; i++) {
        process(count + 1, i, tmp);
    }
}

void solve() {
    input();
    process(0, -1, map);
    cout << answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
