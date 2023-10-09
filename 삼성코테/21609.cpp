#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int black = -1;
const int rainbow = 0;
const int emp = -2;
int n,m,answer;
int map[20][20];
bool visited[20][20];
bool check[20][20];
vector<pair<int,int>> group;
int group_rainbow;

void input() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
}

bool check_range(int x,int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs(int x,int y) {
    fill(&check[0][0],&check[19][20],false);
    queue<pair<int,int>> q;
    int block = map[x][y];
    int rb = 0;
    q.push({x,y});
    check[x][y] = true;
    vector<pair<int,int>> grp;
    grp.push_back({x,y});

    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = fx + "2011"[i] - '1';
            int ny = fy + "1120"[i] - '1';

            if(!check_range(nx,ny)) {
                continue;
            }
            if(check[nx][ny]) {
                continue;
            }
            if(map[nx][ny]==rainbow) {
                ++rb;
                q.push({nx,ny});
                grp.push_back({nx,ny});
                check[nx][ny] = true;
            }
            if(map[nx][ny]==block) {
                q.push({nx,ny});
                grp.push_back({nx,ny});
                check[nx][ny] = true;
            }
        }
    }

    if(grp.size()<2) {
        return;
    }
    for(auto g:grp) {
        visited[g.first][g.second] = true;
    }
    if(group.size()==grp.size()) {
        if(group_rainbow>rb) {
            return;
        } else {
            group = grp;
            group_rainbow = rb;
        }
    } else if(group.size()<grp.size()) {
        group = grp;
        group_rainbow = rb;
    }
}

void find_group() {
    fill(&visited[0][0],&visited[19][20],false);
    group_rainbow = 0;
    group.clear();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]) {
                continue;
            }
            if(map[i][j]<=rainbow) {
                continue;
            }
            bfs(i,j);
        }
    }
}

void remove_block() {
    int score = group.size();
    answer += (score*score);
    for(auto g:group) {
        map[g.first][g.second] = emp;
    }
}

void spin(int ax,int ay,int bx,int by) {
    deque<int> dq;
    for(int i=ay; i<=by; i++) {
        dq.push_back(map[ax][i]);
    }
    for(int i=ax+1; i<=bx; i++) {
        dq.push_back(map[i][by]);
    }
    for(int i=by-1; i>=ay; i--) {
        dq.push_back(map[bx][i]);
    }
    for(int i=bx-1; i>ax; i--) {
        dq.push_back(map[i][ay]);
    }
    int iter = bx-ax;
    for(int i=1; i<=iter; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for(int i=ay; i<=by; i++) {
        map[ax][i] = dq.front();
        dq.pop_front();
    }
    for(int i=ax+1; i<=bx; i++) {
        map[i][by] = dq.front();
        dq.pop_front();
    }
    for(int i=by-1; i>=ay; i--) {
        map[bx][i] = dq.front();
        dq.pop_front();
    }
    for(int i=bx-1; i>ax; i--) {
        map[i][ay] = dq.front();
        dq.pop_front();
    }
}

void rotate() {
    int ax,ay,bx,by;
    ax = ay = 0;
    bx = by = n-1;
    while(ax<=bx && ay<=by) {
        spin(ax,ay,bx,by);
        ++ax;
        ++ay;
        --bx;
        --by;
    }
}

void gravity() {
    for(int i=0; i<n; i++) {
        for(int j=n-2; j>=0; j--) {
            int nx = j;
            int ny = i;
            if(map[nx][ny]==black) {
                continue;
            }
            while(1) {
                if(!check_range(nx+1,ny)) {
                    break;
                }
                ++nx;
                if(map[nx][ny]!=emp) {
                    break;
                }
                map[nx][ny] = map[nx-1][ny];
                map[nx-1][ny] = emp;
            }
        }
    }
}

void solution() {
    while(1) {
        find_group();
        if(group.empty()) {
            break;
        }
        remove_block();
        gravity();
        rotate();
        gravity();
    }
    cout<<answer;
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
