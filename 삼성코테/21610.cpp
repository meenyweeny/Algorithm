#include<iostream>
#include<vector>
using namespace std;

int n,m,d,s;
int map[50][50];
bool disappeared[50][50];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int cx[4] = {-1,-1,1,1};
int cy[4] = {-1,1,-1,1};
vector<pair<int,int>> cloud;

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

int get_position(int x) {
    if(x>=0 && x<n) {
        return x;
    } else if(x>=n) {
        while(1) {
            if(x>=0 && x<n) {
                break;
            }
            x -= n;
        }
    } else {
        while(1) {
            if(x>=0 && x<n) {
                break;
            }
            x += n;
        }
    }
    return x;
}

void move_cloud() {
    int size = cloud.size();
    for(int i=0; i<size; i++) {
        cloud[i] = {get_position(cloud[i].first + (dx[d] * s)),
                    get_position(cloud[i].second + (dy[d] * s))};
    }
}

void cloud_rain() {
    for(auto c:cloud) {
        ++map[c.first][c.second];
    }
}

void disappear_cloud() {
    fill(&disappeared[0][0], &disappeared[49][50], false);
    for(auto c:cloud) {
        disappeared[c.first][c.second] = true;
    }
    cloud.clear();
}

void copy_magic() {
    int copymap[50][50];
    fill(&copymap[0][0],&copymap[49][50],0);
    for(auto c:cloud) {
        for(int i=0; i<4; i++) {
            int nx = c.first + cx[i];
            int ny = c.second + cy[i];
            if(!check_range(nx,ny)) {
                continue;
            }
            if(map[nx][ny]!=0) {
                ++copymap[c.first][c.second];
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            map[i][j] += copymap[i][j];
        }
    }
}

void make_cloud() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j]>=2) {
                if(!disappeared[i][j]) {
                    map[i][j]-=2;
                    cloud.push_back({i,j});
                }
            }
        }
    }
}

void solve() {
    input();
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});
    cloud.push_back({n-1,0});
    cloud.push_back({n-1,1});
    while(m--) {
        cin>>d>>s;
        --d;
        move_cloud(); //모든 구름이 d방향으로 s만큼 이동
        cloud_rain(); //구름에서 비가 내림
        copy_magic(); //물복사버그
        disappear_cloud(); //구름이 모두 사라짐
        make_cloud(); //물의 양이 2이상인 모든 칸에 구름이 생김
    }
    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            answer += map[i][j];
        }
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
