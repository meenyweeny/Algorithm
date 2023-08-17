#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct battery {
    int x, y, c, p;
};

int m, a;
int answer, asum, bsum;
vector<pair<int,int>> map[10][10];
int ma[100], mb[100];
battery info[8];
bool used[8];

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j].clear();
            map[i][j].push_back({-1,0});
        }
    }
    answer = -1;
    asum = bsum = 0;
}

void input() {
    cin >> m >> a;
    for (int i = 0; i < m; i++) {
        cin >> ma[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> mb[i];
    }
    for (int i = 0; i < a; i++) {
        cin >> info[i].y >> info[i].x >> info[i].c >> info[i].p;
        --info[i].x;
        --info[i].y;
    }
}

bool check_range(int x, int y) {
    return x >= 0 && y >= 0 && x < 10 && y < 10;
}

void set_battery_zone() {
    for (int b = 0; b < a; b++) {
        battery now = info[b];
        int bx = now.x;
        int by = now.y;
        int range = now.c;
        int power = now.p;
        int nx = bx;
        int ny = by;

        map[bx][by].push_back({b,power});

        for (int i = 0; i < range; i++) {
            if (check_range(nx, ++ny)) {
                map[nx][ny].push_back({b,power});
            } else {
                break;
            }
        }
        ny = by;
        for (int i = 0; i < range; i++) {
            if (check_range(nx, --ny)) {
                map[nx][ny].push_back({b,power});
            } else {
                break;
            }
        }

        int weight = 1;
        for (int i = range - 1; i >= 0; i--) {
            if (weight > range) {
                break;
            }
            nx = bx - weight;
            ny = by;
            if (check_range(nx, ny)) {
                map[nx][ny].push_back({b,power});
            } else {
                break;
            }
            ny = by;
            for (int j = 0; j < i; j++) {
                if (check_range(nx, ++ny)) {
                    map[nx][ny].push_back({b,power});
                } else {
                    break;
                }
            }
            ny = by;
            for (int j = 0; j < i; j++) {
                if (check_range(nx, --ny)) {
                    map[nx][ny].push_back({b,power});
                }
                else {
                    break;
                }
            }
            ++weight;
        }

        weight = 1;
        for (int i = range - 1; i >= 0; i--) {
            if (weight > range) {
                break;
            }
            nx = bx + weight;
            ny = by;
            if (check_range(nx, ny)) {
                map[nx][ny].push_back({b,power});
            } else {
                break;
            }
            ny = by;
            for (int j = 0; j < i; j++) {
                if (check_range(nx, ++ny)) {
                    map[nx][ny].push_back({b,power});
                } else {
                    break;
                }
            }
            ny = by;
            for (int j = 0; j < i; j++) {
                if (check_range(nx, --ny)) {
                    map[nx][ny].push_back({b,power});
                } else {
                    break;
                }
            }
            ++weight;
        }
    }
}

void sort_all_battery() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sort(map[i][j].begin(), map[i][j].end(), comp);
        }
    }
}

bool is_same_place(int ax, int ay, int bx, int by) {
    return ax == bx && ay == by;
}

pair<int, int> get_proper_power(int x, int y) {
    if (map[x][y].size() == 1) {
        return { 0,0 };
    } else if (map[x][y].size() == 2) {
        return { map[x][y][0].second/2, map[x][y][0].second/2 };
    } else {
        return { map[x][y][0].second, map[x][y][1].second};
    }
}

pair<int,int> get_proper_pair(int ax,int ay,int bx,int by) {
    int aidx = map[ax][ay][0].first;
    int aweight = map[ax][ay][0].second;
    int bidx = map[bx][by][0].first;
    int bweight = map[bx][by][0].second;
    if(aidx == bidx) {
        if(map[ax][ay][1].second > map[bx][by][1].second) {
            aweight = map[ax][ay][1].second;
        } else {
            bweight = map[bx][by][1].second;
        }
    }
    return {aweight, bweight};
}

void procedure() {
    int ax, ay, bx, by;
    ax = ay = 0;
    bx = by = 9;
    asum = map[ax][ay][0].second;
    bsum = map[bx][by][0].second;
    for (int i = 0; i < m; i++) {
        fill(used,used+8,false);
        ax += ("10121"[ma[i]] - '1');
        ay += ("11210"[ma[i]] - '1');
        bx += ("10121"[mb[i]] - '1');
        by += ("11210"[mb[i]] - '1');
        if (is_same_place(ax, ay, bx, by)) {
            pair<int, int> k = get_proper_power(ax, ay);
            asum += k.first;
            bsum += k.second;
            continue;
        }
        if(map[ax][ay].size()==1 && map[bx][by].size()>1) {
            bsum += map[bx][by][0].second;
        } else if(map[ax][ay].size()>1 && map[bx][by].size()==1) {
            asum += map[ax][ay][0].second;
        } else if(map[ax][ay].size()>1 && map[bx][by].size()>1) {
            pair<int,int> k = get_proper_pair(ax,ay,bx,by);
            asum += k.first;
            bsum += k.second;
        }
    }
    answer = asum + bsum;
}

void solution() {
    set_battery_zone();
    sort_all_battery();
    procedure();
}

void solve() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        init();
        input();
        solution();
        cout << '#' << tc << ' ' << answer << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
