#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x,y;
};

int n,m,d,s;
int map[51][51];
vector<Point> cloud;
vector<Point> water;
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
bool visited[51][51];

void input() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
        }
    }
}

int get_next_pos(int dir,int x) {
    x += (dir*s);
    if(x>0) {
        while(1) {
            if(x<=n) {
                break;
            }
            x -= n;
        }
    } else {
        while(1) {
            if(x>0) {
                break;
            }
            x += n;
        }
    }
    return x;
}

void move_cloud() {
    for(int i=0; i<cloud.size(); i++) {
        cloud[i].x = get_next_pos(dx[d],cloud[i].x);
        cloud[i].y = get_next_pos(dy[d],cloud[i].y);
        ++map[cloud[i].x][cloud[i].y];
    }
}

bool check_range(int x,int y) {
    return x>0 && x<=n && y>0 && y<=n;
}

void copy_water() {
    vector<int> v;
    for(auto w:water) {
        int count = 0;
        for(int i=0; i<4; i++) {
            int nx = w.x + "0022"[i] - '1';
            int ny = w.y + "0202"[i] - '1';
            if(!check_range(nx,ny)) {
                continue;
            }
            count += (map[nx][ny] != 0);
        }
        v.push_back(count);
    }
    fill(&visited[0][0],&visited[50][51],false);
    for(int i=0; i<water.size(); i++) {
        map[water[i].x][water[i].y] += v[i];
        visited[water[i].x][water[i].y] = true;
    }
}

void make_new_cloud() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]>=2 && !visited[i][j]) {
                cloud.push_back({i,j});
                map[i][j] -= 2;
            }
        }
    }
    water.clear();
}

void routine() {
    move_cloud();
    water = cloud;
    cloud.clear();
    copy_water();
    make_new_cloud();
}

void solution() {
    cloud.push_back({n-1,1}); //초기 구름
    cloud.push_back({n-1,2});
    cloud.push_back({n,1});
    cloud.push_back({n,2});
    while(m--) {
        cin>>d>>s;
        --d;
        routine();
    }
    int answer = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            answer += map[i][j];
        }
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
