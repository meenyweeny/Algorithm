#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int n,m,width;
int map[64][64];
bool visited[64][64];
vector<int> level;

void input() {
    cin >> n >> m;
    width = pow(2,n);
    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            cin>>map[i][j];
        }
    }
    int l;
    while(m--) {
        cin>>l;
        level.push_back(l);
    }
}

int get_sum() {
    int ret = 0;
    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            if(map[i][j]>0) {
                ret += map[i][j];
            }
        }
    }
    return ret;
}

bool check_range(int x,int y) {
    return x>=0 && x<width && y>=0 && y<width;
}

int bfs(int x,int y) {
    queue<pair<int,int>> q;
    int count = 1;
    q.push({x,y});
    visited[x][y] = true;

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
            if(visited[nx][ny]) {
                continue;
            }
            if(map[nx][ny]<=0) {
                continue;
            }
            q.push({nx,ny});
            visited[nx][ny] = true;
            ++count;
        }
    }
    return count;
}

int get_island() {
    int area = 0;
    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            if(visited[i][j]) {
                continue;
            }
            if(map[i][j]<=0) {
                continue;
            }
            area = max(area,bfs(i,j));
        }
    }
    return area;
}

void rotate(int ax,int ay,int bx,int by) {
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
    while(iter--) {
        dq.push_front(dq.back());
        dq.pop_back();
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

void spin(int sx,int sy,int ex,int ey) {
    while(sx<=ex && sy<=ey) {
        rotate(sx,sy,ex,ey);
        ++sx;
        ++sy;
        --ex;
        --ey;
    }
}

void spin_arr(int w) {
    int x = pow(2,w);
    for(int i=0; i<width; i+=x) {
        for(int j=0; j<width; j+=x) {
            spin(i,j,i+x-1,j+x-1);
        }
    }
}

void minus_ice() {
    vector<pair<int,int>> cand;
    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            int have = 0;
            for(int k=0; k<4; k++) {
                int nx = i + "2011"[k] - '1';
                int ny = j + "1120"[k] - '1';

                if(!check_range(nx,ny)) {
                    continue;
                }
                if(map[nx][ny]<=0) {
                    continue;
                }
                ++have;
            }
            if(have<3) {
                cand.push_back({i,j});
            }
        }
    }
    for(auto c:cand) {
        --map[c.first][c.second];
    }
}

void solution() {
    for(auto l:level) {
        spin_arr(l);
        minus_ice();
    }
    cout<<get_sum()<<'\n';
    cout<<get_island();
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
