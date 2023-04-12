#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Point {
    int x,y;
};

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int mx[4] = {-1,-1,1,1};
int my[4] = {-1,1,1,-1};
int n;
int map[52][52];
bool visited[52][52];
vector<Point> cloud;

void initialize() {
    cloud.push_back({n,1});
    cloud.push_back({n,2});
    cloud.push_back({n-1,1});
    cloud.push_back({n-1,2});
}

int convert(int x) {
    if(x<1) {
        x = n;
    } else if(x>n) {
        x = 1;
    }
    return x;
}

bool is_in_copy_range(int x,int y) {
    return x>0 && x<=n && y>0 && y<=n;
}

void move_cloud(int d,int s) {
    for(int i=0; i<cloud.size(); i++) {
        for(int j=0; j<s; j++) {
            cloud[i].x += dx[d];
            cloud[i].y += dy[d];
            cloud[i].x = convert(cloud[i].x);
            cloud[i].y = convert(cloud[i].y);
        }
        visited[cloud[i].x][cloud[i].y] = true;
    }
}

void make_rain() {
    for(int i=0; i<cloud.size(); i++) {
        ++map[cloud[i].x][cloud[i].y];
    }
}

void copy_water() {
    for(int i=0; i<cloud.size(); i++) {
        int nx = cloud[i].x;
        int ny = cloud[i].y;
        int cnt = 0;
        for(int k=0; k<4; k++) {
            int fx = nx + mx[k];
            int fy = ny + my[k];
            if(!is_in_copy_range(fx,fy)) {
                continue;
            }
            cnt += (map[fx][fy]>0);
        }
        map[nx][ny] += cnt;
    }
}

void make_cloud() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(visited[i][j]) {
                continue;
            }
            if(map[i][j]<2) {
                continue;
            }
            map[i][j]-=2;
            cloud.push_back({i,j});
        }
    }
}

void solution(int d,int s) {
    memset(visited,false,sizeof(visited));
    move_cloud(d,s);
    make_rain();
    copy_water();
    cloud.clear();
    make_cloud();
}

void solve() {
    cin>>n;
    int m;
    cin>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }
    initialize();
    int d,s;
    while(m--) {
        cin>>d>>s;
        --d;
        solution(d,s);
    }

    int answer = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
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
}
